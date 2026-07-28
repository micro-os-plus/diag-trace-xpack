---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

title: µOS++ Tracing Infrastructure API Reference
slug: /api/
description: The main page of the API documentation
custom_edit_url: null
keywords:
  - doxygen
  - reference

---

<div class="doxyPage">

µOS++ Tracing Infrastructure topics with brief descriptions are:

<table class="doxyTreeTable">
<colgroup><col style="width:40%"><col></colgroup>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 12px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus">µOS++ Topics</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Topics related to the µOS++ framework
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 24px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace">µOS++ Tracing Infrastructure</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Diagnostic trace output channel for µOS++ applications
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api">C++ API</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C++ tracing functions in the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">micro_os_plus::trace</a></span> namespace
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation">Implementation functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
User-supplied back-end primitives that define the trace channel
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main">Main functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Primary C++ functions for outputting trace messages
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra">Utility functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Supplementary C++ trace utility functions
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api">C API</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C-linkage wrapper functions for the tracing infrastructure
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation">Implementation functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
C wrappers for the user-supplied back-end primitives
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main">Main functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Primary C functions for outputting trace messages
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 48px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra">Utility functions</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Supplementary C trace utility functions
</td>
</tr>

<tr class="doxyTreeItem">
<td class="doxyTreeItemLeft" align="left" valign="top">
<span style="width: 36px; display: inline-block;"></span>
<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config">Configuration</a>
</td>
<td class="doxyTreeItemRight" align="left" valign="top">
Configuration macros
</td>
</tr>

</table>

## Description



<p>The <b>µOS++ Tracing Infrastructure</b> (<span class="doxyComputerOutput">@micro-os-plus/diag-trace</span>) is a lightweight, header-only-friendly C++20 library that provides a dedicated diagnostic output channel for embedded and bare-metal applications. It is part of the broader <a href="https://micro-os-plus.github.io/">µOS++ project</a>.</p>


<p>The library exposes an API that closely mirrors the standard C output functions — <span class="doxyComputerOutput">printf()</span>, <span class="doxyComputerOutput">puts()</span>, and <span class="doxyComputerOutput">putchar()</span> — but routes all output through an independent, user-supplied back-end rather than through the standard library's <span class="doxyComputerOutput">stdout</span>. This separation keeps diagnostic traffic out of the normal I/O path, which is particularly valuable on targets where <span class="doxyComputerOutput">stdout</span> is not available or is connected to application-level data streams.</p>


<p>The C++ API is built around the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">micro_os_plus::trace::detail::tracer</a></span> class template, parameterised on a <em>policy</em> class that supplies three static primitives: <span class="doxyComputerOutput">initialise()</span>, <span class="doxyComputerOutput">write()</span>, and <span class="doxyComputerOutput">flush()</span>. A default policy, <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">micro_os_plus::trace::detail::implementation</a></span>, is declared for production use. The free functions in the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">micro_os_plus::trace</a></span> namespace — <span class="doxyComputerOutput">trace::printf()</span>, <span class="doxyComputerOutput">trace::puts()</span>, <span class="doxyComputerOutput">trace::putchar()</span>, and so on — are thin wrappers over this default instantiation. A compatible C API, prefixed with <span class="doxyComputerOutput">micro_os_plus_trace_</span>, is also provided for use from plain C translation units.</p>


<p>Trace support is activated at compile time by defining the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#gac21aa3324300f25da16bf17b95afbd90">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</a></span> preprocessor macro. When the macro is absent, every trace call is replaced by an empty inline function, so application code never needs to be surrounded by <span class="doxyComputerOutput">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span> guards. The trade-off is that the trace header must always be included, but this is a minor inconvenience compared with the readability benefit of unconditional call sites.</p>


<p>To integrate the library into a project, the developer must provide a single translation unit that implements the three static methods of the chosen policy class. Ready-made implementations for common targets — ARM semihosting, Arm ITM, SEGGER RTT, and POSIX file descriptors — are available as separate xPack components.</p>


:::note
For comparison, the original Doxygen html pages continue to be available via the <a href="pathname:///doxygen/topics.html">.../doxygen/*.html</b></a> URLs.
:::

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
