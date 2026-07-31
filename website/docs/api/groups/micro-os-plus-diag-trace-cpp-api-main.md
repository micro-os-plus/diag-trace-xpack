---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-cpp-api-main
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Main functions

<p>Primary C++ functions for outputting trace messages. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (const char *format,...) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted string to the trace output channel. <a href="#ga1147fe38ae648cb84a4e668cf68c405b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a> (int c) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the single character to the trace output channel. <a href="#ga8b4745ad9d5b6a65f95f40e70acc518a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga35f7d251803f518a84162208e8165d0a">puts</a> (const char *s="") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the string and a line terminator to the trace output channel. <a href="#ga35f7d251803f518a84162208e8165d0a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gafb94817670ea90990b925e71d14ef910">vprintf</a> (const char *format, std::va_list arguments) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted variable arguments list to the trace output channel. <a href="#gafb94817670ea90990b925e71d14ef910">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Primary C++ functions for outputting trace messages.</p>


<p>These functions serve as the primary methods for outputting trace messages in C++ projects.</p>


<div class="doxySectionDef">

## Functions

### printf() {#ga1147fe38ae648cb84a4e668cf68c405b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::printf (const char * format, ...)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
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


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7fb471958c000ac75290f5cc68522953">tracer&lt;T&gt;::printf()</a>. Subject to the same fixed-size stack buffer constraint and truncation behaviour; the return value cannot be used to detect whether truncation occurred.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00249">249</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga1147fe38ae648cb84a4e668cf68c405b">249</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">    std::va_list arguments;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">252</span><span class="doxyLineContent"><span class="doxyHighlight">    va_start (arguments, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">253</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">254</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ret</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">255</span><span class="doxyLineContent"><span class="doxyHighlight">        = <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">detail::tracer&lt;detail::implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">256</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">257</span><span class="doxyLineContent"><span class="doxyHighlight">    va_end (arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">258</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> ret;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">micro_os_plus::trace::detail::tracer&lt; T &gt;::dump_args</a>.</p>

</div>
</div>

### putchar() {#ga8b4745ad9d5b6a65f95f40e70acc518a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::putchar (int c)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
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


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">tracer&lt;T&gt;::putchar()</a>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00274">274</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga8b4745ad9d5b6a65f95f40e70acc518a">274</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">275</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">276</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">detail::tracer&lt;detail::implementation&gt;::putchar</a> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">277</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">micro_os_plus::trace::detail::tracer&lt; T &gt;::putchar</a>.</p>

</div>
</div>

### puts() {#ga35f7d251803f518a84162208e8165d0a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::puts (const char * s="")</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
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
<td class="doxyParamItemDescription"><p>A null terminated string (default: empty string).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The total number of bytes written (string + newline), or EOF (-1) if an error occurred.</p></dd>
</dl>


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">tracer&lt;T&gt;::puts()</a>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00268">268</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga35f7d251803f518a84162208e8165d0a">268</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga35f7d251803f518a84162208e8165d0a">puts</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">269</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">270</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">detail::tracer&lt;detail::implementation&gt;::puts</a> (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">271</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">micro_os_plus::trace::detail::tracer&lt; T &gt;::puts</a>.</p>

</div>
</div>

### vprintf() {#gafb94817670ea90990b925e71d14ef910}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::vprintf (const char * format, std::va_list arguments)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
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


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">tracer&lt;T&gt;::vprintf()</a>. Subject to the same fixed-size stack buffer constraint and truncation behaviour; the return value cannot be used to detect whether truncation occurred.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00262">262</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gafb94817670ea90990b925e71d14ef910">262</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gafb94817670ea90990b925e71d14ef910">vprintf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, std::va_list arguments) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">detail::tracer&lt;detail::implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7fb471958c000ac75290f5cc68522953">micro_os_plus::trace::detail::tracer&lt; T &gt;::printf</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
