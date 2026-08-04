# Code Review — `src/` and `include/` Folders

**Reviewer:** GitHub Copilot (Claude Sonnet 4.6)
**Date:** 2026-07-28
**Scope:** `src/trace-c-api.cpp`, `src/trace-cpp-api.cpp`,
`include/micro-os-plus/diag/trace.h`,
`include/micro-os-plus/diag/trace-c-api.h`,
`include/micro-os-plus/diag/trace-cpp-api.h`,
`include/micro-os-plus/diag/inlines/trace-c-api-inlines.h`,
`include/micro-os-plus/diag/inlines/trace-cpp-api-inlines.h`

---

## Summary

The codebase is well-structured and already uses several C++20 features
correctly: concepts, nested namespaces, `explicit template`
instantiation, and conditional `noexcept`. The policy-based `tracer<T>`
design is sound. The following findings are ordered by severity.

**Second-pass status (2026-07-28):** Items 1.1, 1.2, 1.3, 2.1, 3.1, 4.1,
4.2, 4.4, 5.1, and 5.3 have been fixed and verified (native unit tests:
19 checks passed). Section 2.2 as originally numbered ("buffer size
macro should be `constexpr`") was removed after review, as it was
judged low-value; the remaining sections were renumbered accordingly.
Items 2.2 (attribute syntax), 2.3, 2.4, 3.2, 4.3 (partially fixed —
see below), 5.2, and 5.4 (deferred by design) remain open. Two
additional issues were found during this second-pass review; see
Section 6.

---

## 1. Correctness

### 1.1 `format` attribute missing from disabled stubs — HIGH — FIXED

The C stubs in `trace-c-api-inlines.h` (used when
`MICRO_OS_PLUS_DIAG_TRACE_ENABLED` is not defined) omit the
`__attribute__((format(printf, 1, 2)))` annotation:

```c
static inline __attribute__ ((always_inline)) int
micro_os_plus_trace_printf (const char* format, ...)
{
  return 0;
}
```

The C++ disabled stubs in `trace-cpp-api-inlines.h` have the same gap:

```cpp
inline __attribute__ ((always_inline)) int
printf (const char* /* format */, ...) noexcept
{
  return 0;
}
```

Without the `format` attribute, the compiler cannot diagnose format-string
type mismatches when tracing is disabled. Format-string bugs are a class of
real security vulnerability (CWE-134). They will only be caught when
tracing is enabled, which defeats the purpose of compile-time checking.

**Recommendation:** Add `__attribute__((format(printf, 1, 2)))` to both
the `printf` and `vprintf` disabled stubs, in both the C and C++
inline files. The `vprintf` stub should use
`__attribute__((format(printf, 1, 0)))`.

---

### 1.2 `puts` appends newline even when the string write returns zero — FIXED

In `trace-cpp-api-inlines.h`:

```cpp
ssize_t ret = write (s, std::strlen (s));
if (ret >= 0)
  {
    ssize_t ret2 = write ("\n", 1);
    ...
  }
```

If `write` returns 0 for a non-empty string (no bytes transferred, but
no hard error), the condition `ret >= 0` is still true and the newline
is appended. The channel then receives a bare `\n` with no preceding
content, which corrupts the trace output stream. The condition should
be changed to `ret == static_cast<ssize_t>(std::strlen(s))` (all bytes
written), or the write result should be compared against the requested
byte count. A simpler conservative fix is:

```cpp
// Only write the newline when the string write fully succeeded.
if (ret >= 0 && (std::strlen (s) == 0
                 || ret == static_cast<ssize_t> (std::strlen (s))))
```

Note that this also requires caching `std::strlen(s)` to avoid
computing it twice.

---

### 1.3 `putchar` converts `int` to `char` — possible sign loss — FIXED

```cpp
char ch = static_cast<char> (c);
ssize_t ret = write (&ch, 1);
```

When `char` is signed (which is implementation-defined) and `c` is in
the range 128–255, `static_cast<char>(c)` produces an
implementation-defined result. The conversion should use
`unsigned char`:

```cpp
auto ch = static_cast<unsigned char> (c);
```

`write` takes `const void*`, so passing `&ch` remains valid.

---

## 2. C++20 Improvements

### 2.1 Redundant conditional `noexcept` in `tracer<T>` — LOW — FIXED

The `tracer<T>` delegation methods use:

```cpp
static void
initialise (void) noexcept (noexcept (T::initialise ()))
```

However, the `trace_policy` concept already requires all three methods
to be `noexcept`:

```cpp
{ T::initialise () } noexcept -> std::same_as<void>;
```

The conditional form therefore always resolves to `noexcept(true)`.
The unconditional form is cleaner and conveys the intent directly:

```cpp
static void
initialise () noexcept
```

Apply the same change to the `write` and `flush` delegating methods.

---

### 2.2 `[[gnu::format(printf, ...)]]` attribute syntax — OPEN

The code uses `__attribute__((format(printf, 1, 2)))`. In C++20, the
`[[...]]` attribute syntax is preferred over GCC extension syntax for
standard-compliant attributes. The GCC/Clang equivalent is:

```cpp
[[gnu::format(printf, 1, 2)]]
int printf (const char* format, ...) noexcept;
```

This is purely stylistic; both forms are accepted by GCC and Clang.

---

### 2.3 `(void)` parameter style in C++ declarations — OPEN

Functions throughout `trace-cpp-api.h` use the C-style `(void)` for
empty parameter lists:

```cpp
void initialise (void) noexcept;
```

In C++, `()` and `(void)` are equivalent. The C-style form adds
clutter in a pure C++ header. Since the project already mandates
C++20, `()` is the idiomatic form:

```cpp
void initialise () noexcept;
```

Note: the C API in `trace-c-api.h` must retain `(void)` for C
compatibility.

---

### 2.4 `std::span<const std::byte>` overloads for `write` — OPEN

The `write` primitives use the POSIX-style `(const void*, std::size_t)`
signature. A C++20 overload accepting `std::span<const std::byte>`
would be more type-safe and eliminate the need to compute buffer sizes
at call sites:

```cpp
static ssize_t
write (std::span<const std::byte> data) noexcept;
```

This is an additive change that does not break existing call sites.
The existing `(const void*, std::size_t)` overload should be kept for
the C API bridge and for code passing non-byte buffers.

---

## 3. Dead Code and Clutter

### 3.1 Commented-out `#include` directives — FIXED

Several files contain commented-out includes that serve no purpose:

- `trace-c-api.h`: `// #include <stdint.h>`, `// #include <stdlib.h>`
- `trace-cpp-api.h`: `// #include <cstdint>`, `// #include <cstdlib>`

These should be removed entirely. Their presence implies they were once
needed (or might be needed), which is misleading. If they were
deliberately left as placeholders, that intent should be documented,
or they should be removed.

---

### 3.2 Unnecessary `-Wpre-c++17-compat` suppression pragma — OPEN

```cpp
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
namespace micro_os_plus::trace
```

The nested namespace syntax `A::B` is a C++17 feature. The project
already enforces C++20 via a `#error` in `trace.h`. No translation unit
can reach this code without C++20 being active, making the pragma
redundant. It should be removed.

---

## 4. Documentation

### 4.1 Double space in `trace.h` `@file` block — FIXED

```
 * Top-level umbrella header; the only file users need to  include directly.
```

There are two spaces before `include`. This is a typographical error.

---

### 4.2 Missing trailing period on `@brief` in `trace-cpp-api.h` — FIXED

```
 * @brief C++ header file with the declarations for the C++ trace API
```

The `@brief` sentence is missing a trailing period. All other `@brief`
entries in the codebase end with a period.

---

### 4.3 `#error` messages contain unbalanced quotes — PARTIALLY FIXED

In `trace-c-api.h` and `trace-cpp-api.h`:

```cpp
#error "Do not include this file directly; use "micro-os-plus/diag/trace.h"."
```

The inner double-quotes around the include path are not escaped.
GCC and Clang accept this in `#error` directives (the entire line
is treated as a raw message), but it is technically non-conforming
and confusing. The conventional form uses angle brackets or no
quoting on the inner path:

```cpp
#error "Do not include this file directly; use <micro-os-plus/diag/trace.h>."
```

**Status:** `trace-c-api.h` and `trace-cpp-api.h` have been fixed (the
message now reads `use micro-os-plus/diag/trace.h.` without inner
quotes). However, the two inline-stub headers were missed and still
contain the original defective message:

```cpp
#error "Do not include this file directly; use "micro-os-plus/diag/trace.h"."
```

This is present in both
[trace-c-api-inlines.h](include/micro-os-plus/diag/inlines/trace-c-api-inlines.h#L28)
and
[trace-cpp-api-inlines.h](include/micro-os-plus/diag/inlines/trace-cpp-api-inlines.h#L28).
The same correction needs to be applied there for consistency.

---

### 4.4 Truncation in `vprintf` is undocumented at the API level — FIXED

The `@details` of `micro_os_plus_trace_vprintf` and
`micro_os_plus::trace::vprintf` documents the truncation behaviour.
However, the truncation is silent: the return value reflects only the
bytes actually written to the channel, not the length that the format
string would have produced. Callers have no way to detect whether
output was truncated.

This is documented in the implementation comment inside
`tracer<T>::vprintf` but not in the public Doxygen `@details` for the
free functions. Consider adding a sentence to the `@details` of the
public API declarations explicitly noting that truncation is
undetectable from the return value.

---

## 5. Style and Maintainability

### 5.1 Inconsistent include guard style: `#ifdef` vs `#if defined` — FIXED

`trace-cpp-api-inlines.h` uses:

```cpp
#ifdef __cplusplus
```

All other occurrences in the codebase use:

```cpp
#if defined(__cplusplus)
```

These are semantically identical, but the inconsistency is jarring.
The `#if defined(...)` form should be used throughout for uniformity.

---

### 5.2 Free function declarations not marked `inline` — OPEN

In `trace-cpp-api.h`, the free functions (`initialise`, `write`,
`flush`, `printf`, etc.) are declared without `inline`:

```cpp
void initialise (void) noexcept;
```

Their definitions in `trace-cpp-api-inlines.h` carry `inline`:

```cpp
inline void
initialise (void) noexcept
{ ... }
```

In C++, a function becomes inline if `inline` appears on any
declaration in the translation unit where the definition is visible.
Since the inlines file is always included at the bottom of
`trace-cpp-api.h`, the result is correct. However, the mismatch
between the declaration (no `inline`) and the definition (`inline`)
is misleading. Readers examining the declaration alone cannot tell
that the function is inlined.

The forward declarations should also carry `inline`, or the separate
declarations should be removed and the functions defined inline
directly in the single location where they are meant to appear.

---

### 5.3 `using namespace` in `trace-c-api.cpp` — FIXED

```cpp
using namespace micro_os_plus::trace::detail;
```

In a `.cpp` file this is acceptable, but a namespace alias is both
clearer and safer as the namespace grows:

```cpp
namespace detail = micro_os_plus::trace::detail;
```

This is low-priority but improves readability at call sites.

---

### 5.4 `ssize_t` in the concept definition is a POSIX type — OPEN (deferred)

The `trace_policy` concept constrains `write` to return `ssize_t`:

```cpp
{ T::write (buf, n) } noexcept -> std::same_as<ssize_t>;
```

`ssize_t` is defined by POSIX, not by the ISO C++ standard. It is
provided on the target platforms through `<sys/types.h>`, but its
use in a concept definition ties the concept semantics to POSIX.
An alternative is `std::ptrdiff_t`, which is always available in
`<cstddef>` and is the signed counterpart of `std::size_t`:

```cpp
{ T::write (buf, n) } noexcept -> std::same_as<std::ptrdiff_t>;
```

This change would require updating all three API layers
(`trace_policy`, `implementation`, the free functions, and the C
API), so it is a non-trivial refactor. It is worth considering for
a future major version.

---

## 6. New Findings — Second-Pass Review (2026-07-28)

### 6.1 `putchar` documentation still says `char`, but the implementation
now converts to `unsigned char` — DOCUMENTATION BUG — FIXED

The 1.3 fix changed the conversion in `tracer<T>::putchar` from
`static_cast<char>` to `static_cast<unsigned char>` to avoid
implementation-defined sign loss. The Doxygen `@details` for the
public declarations were not updated to match and still read:

```
Converts @p c to `char` and passes it as a one-byte buffer to
micro_os_plus_trace_write.
```

This is present in both
[trace-c-api.h](include/micro-os-plus/diag/trace-c-api.h#L181) (for
`micro_os_plus_trace_putchar`) and
[trace-cpp-api.h](include/micro-os-plus/diag/trace-cpp-api.h#L537)
(for `tracer<T>::putchar`). Both should read "Converts @p c to
`unsigned char`" to accurately describe the current behaviour.

---

### 6.2 Stray blank line inside a Doxygen comment block in
`trace-cpp-api.cpp` — COSMETIC

```cpp
 * The empty inline stubs (used when tracing is disabled) are located in
 * @ref trace-cpp-api-inlines.h, included at the bottom of
 * @ref trace-cpp-api.h.

 */
```

There is a blank line (missing the leading ` * `) immediately before
the closing `*/` in the file-level comment of
[trace-cpp-api.cpp](src/trace-cpp-api.cpp#L23). This is inconsistent
with the equivalent comment block in `trace-c-api.cpp`, which has no
such gap, and should be removed.

---

## What Was Left Out

- No performance profiling was performed; the stack-allocated printf
  buffer is a known design trade-off.
- The `dump_args` signature correctly uses `char* argv[]` (not
  `const char*`) to match the standard `main` signature, so no
  implicit conversion is required at call sites. This was examined
  and found to be correct by design.
- Thread safety is explicitly disclaimed in the documentation and was
  not evaluated here.
- The explicit template instantiation (`extern template` /
  `template class tracer<implementation>`) was examined and found
  to be correctly paired.
