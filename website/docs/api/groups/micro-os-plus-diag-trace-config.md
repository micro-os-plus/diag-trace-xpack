---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-config
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Configuration

<p>Configuration macros. <a href="#details">More...</a></p>

## Macro Definitions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gac21aa3324300f25da16bf17b95afbd90">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Enables the output of trace messages. <a href="#gac21aa3324300f25da16bf17b95afbd90">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">#define</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga2084a7003aa78ca9574f96fcb9b5ff4e">MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER</a>&nbsp;&nbsp;&nbsp;(200)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The size, in bytes, of the stack buffer used to format trace messages. <a href="#ga2084a7003aa78ca9574f96fcb9b5ff4e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Configuration macros.</p>


<p>The µOS++ Tracing Infrastructure library uses several preprocessor macros to enable it and to configure various options.</p>


<div class="doxySectionDef">

## Macro Definitions

### MICRO\_OS\_PLUS\_DIAG\_TRACE\_ENABLED {#gac21aa3324300f25da16bf17b95afbd90}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_DIAG_TRACE_ENABLED</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Enables the output of trace messages.</p>


<p>The macro is intended to be defined by the user, for debug builds, typically in the library's own <span class="doxyComputerOutput">micro-os-plus/diag/trace-defines.h</span> configuration file or the project <span class="doxyComputerOutput">micro-os-plus/project-config.h</span> configuration file.</p>


<p>When <span class="doxyComputerOutput"><a href="#gac21aa3324300f25da16bf17b95afbd90">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</a></span> is defined, the C++ and C trace functions are compiled to their full implementations, declared in <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a> and <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>, which forward all calls to <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">micro_os_plus::trace::detail::tracer</a>&lt;<a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">micro_os_plus::trace::detail::implementation</a>&gt;</span>.</p>


<p>When it is not defined, which is the usual case for release builds, all trace functions are inlined to empty (or trivial pass-through) bodies. This approach allows trace calls to remain in the code unconditionally, without being wrapped in <span class="doxyComputerOutput">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span> guards, while still being fully eliminated from the generated binary.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h/#l00051">51</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">trace.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gac21aa3324300f25da16bf17b95afbd90">51</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_DIAG_TRACE_ENABLED</span></span></div>

</div>

</div>
</div>

### MICRO\_OS\_PLUS\_DIAG\_TRACE\_PRINTF\_BUFFER\_ARRAY\_SIZE\_INTEGER {#ga2084a7003aa78ca9574f96fcb9b5ff4e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">#define MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER&nbsp;&nbsp;&nbsp;(200)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The size, in bytes, of the stack buffer used to format trace messages.</p>


<p>This buffer is allocated on the stack by <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">tracer&lt;T&gt;::vprintf()</a> to hold the message formatted by <span class="doxyComputerOutput">vsnprintf()</span> before it is forwarded to the trace channel <span class="doxyComputerOutput">write()</span> implementation. Output that exceeds this size is silently truncated.</p>


<p>The definition below only supplies the default value (200 bytes), used when the macro has not already been defined; the actual value may be overridden by the user, typically in the library's own <span class="doxyComputerOutput">micro-os-plus/diag/trace-defines.h</span> configuration file or the project <span class="doxyComputerOutput">micro-os-plus/project-config.h</span> configuration file.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h/#l00055">55</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">trace.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga2084a7003aa78ca9574f96fcb9b5ff4e">55</a></span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER (200)</span></span></div>

</div>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
