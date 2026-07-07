---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-c-api-main
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Main functions

<p>Primary C functions for outputting trace messages. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted string to the trace output channel. <a href="#ga10e8dda4991909bc9b401c4f401f1364">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar</a> (int c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the single character to the trace output channel. <a href="#gaf651ff851996a49b25989c93118142f9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the string and a line terminator to the trace output channel. <a href="#ga378825eb60900b367774de9e76925b0d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga61e826d87556c899edad6f82d7bd36ef">micro_os_plus_trace_vprintf</a> (const char *format, va_list arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted variable arguments list to the trace output channel. <a href="#ga61e826d87556c899edad6f82d7bd36ef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Primary C functions for outputting trace messages.</p>


<p>These functions constitute the primary methods for outputting trace messages in C projects.</p>


<div class="doxySectionDef">

## Functions

### micro\_os\_plus\_trace\_printf() {#ga10e8dda4991909bc9b401c4f401f1364}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus_trace_printf (const char * format, ...)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Write a formatted string to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">format</td>
<td class="doxyParamItemDescription"><p>A null terminated string with the format.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">...</td>
<td class="doxyParamItemDescription"><p>Additional arguments matching the format specifiers.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of bytes written, or -1 if an error occurred.</p></dd>
</dl>


<p>Formatting is performed into a fixed-size stack buffer of <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/inlines/trace-cpp-api-inlines-h/#a2084a7003aa78ca9574f96fcb9b5ff4e">MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER</a></span> bytes (default: 200). If the formatted output exceeds this limit, it is silently truncated before being passed to <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a></span>. The return value reflects the number of bytes actually written, not the number that the format string would have produced.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h/#l00132">132</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h">trace-c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00066">66</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga10e8dda4991909bc9b401c4f401f1364">66</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">67</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">68</span><span class="doxyLineContent"><span class="doxyHighlight">  std::va_list arguments;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">69</span><span class="doxyLineContent"><span class="doxyHighlight">  va_start (arguments, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">70</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">75</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ret = <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">tracer&lt;implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">76</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">  va_end (arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> ret;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>

</div>
</div>

### micro\_os\_plus\_trace\_putchar() {#gaf651ff851996a49b25989c93118142f9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus_trace_putchar (int c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Write the single character to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>A single byte character, passed as an <span class="doxyComputerOutput">int</span>.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The written character as an <span class="doxyComputerOutput">int</span>, or EOF (-1) if an error occurred.</p></dd>
</dl>


<p>Converts <span class="doxyComputerOutput">c</span> to <span class="doxyComputerOutput">char</span> and passes it as a one-byte buffer to <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a></span>. On success, returns the original value of <span class="doxyComputerOutput">c</span>; on failure, returns EOF.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h/#l00186">186</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h">trace-c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00105">105</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaf651ff851996a49b25989c93118142f9">105</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">tracer&lt;implementation&gt;::putchar</a> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">micro_os_plus::trace::detail::tracer&lt; T &gt;::putchar</a>.</p>

</div>
</div>

### micro\_os\_plus\_trace\_puts() {#ga378825eb60900b367774de9e76925b0d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus_trace_puts (const char * s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Write the string and a line terminator to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>A null terminated string.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The total number of bytes written (string + newline), or EOF (-1) if an error occurred.</p></dd>
</dl>


<p>Writes the characters of <span class="doxyComputerOutput">s</span> followed by a single newline character (<span class="doxyComputerOutput">'\n'</span>). Unlike the standard C <span class="doxyComputerOutput">puts()</span>, this function returns the total byte count written, not merely a non-negative indicator. If writing the newline fails after the string has been written successfully, EOF is returned.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h/#l00170">170</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h">trace-c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00094">94</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga378825eb60900b367774de9e76925b0d">94</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">tracer&lt;implementation&gt;::puts</a> (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">micro_os_plus::trace::detail::tracer&lt; T &gt;::puts</a>.</p>

</div>
</div>

### micro\_os\_plus\_trace\_vprintf() {#ga61e826d87556c899edad6f82d7bd36ef}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus_trace_vprintf (const char * format, va_list arguments)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Write a formatted variable arguments list to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">format</td>
<td class="doxyParamItemDescription"><p>A null terminated string with the format.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">arguments</td>
<td class="doxyParamItemDescription"><p>A variable arguments list.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of bytes written, or -1 if an error occurred.</p></dd>
</dl>


<p>Equivalent to <span class="doxyComputerOutput"><a href="#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a></span>, but accepts a <span class="doxyComputerOutput">va_list</span> instead of a variadic argument list. Subject to the same fixed-size stack buffer constraint and truncation behaviour. Typically called by <span class="doxyComputerOutput"><a href="#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a></span>.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h/#l00151">151</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-c-api-h">trace-c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00083">83</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga61e826d87556c899edad6f82d7bd36ef">83</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga61e826d87556c899edad6f82d7bd36ef">micro_os_plus_trace_vprintf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, va_list arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">tracer&lt;implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
