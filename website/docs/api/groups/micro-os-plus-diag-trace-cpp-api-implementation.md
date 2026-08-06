---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-cpp-api-implementation
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Implementation functions

<p>User-supplied back-end primitives that define the trace channel. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gad2196053624765f72c82e983d6d3e512">flush</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="#gad2196053624765f72c82e983d6d3e512">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga2eeb0c01fc5d6e432e319950a94acb2c">initialise</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="#ga2eeb0c01fc5d6e432e319950a94acb2c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">ssize_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gacfbedd8169716b02026a93c948af99c8">write</a> (const void *buf, std::size_t nbyte) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="#gacfbedd8169716b02026a93c948af99c8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>User-supplied back-end primitives that define the trace channel.</p>


<p>The following functions must be implemented by the user and are specific to each individual trace channel.</p>


<div class="doxySectionDef">

## Functions

### flush() {#gad2196053624765f72c82e983d6d3e512}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::flush (void)</td>
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

<p>Flush the trace output channel.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">tracer&lt;T&gt;::flush()</a>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00248">248</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gad2196053624765f72c82e983d6d3e512">248</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gad2196053624765f72c82e983d6d3e512">flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">250</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">detail::tracer&lt;detail::implementation&gt;::flush</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">251</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">micro_os_plus::trace::detail::tracer&lt; T &gt;::flush</a>.</p>

</div>
</div>

### initialise() {#ga2eeb0c01fc5d6e432e319950a94acb2c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::initialise (void)</td>
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

<p>Initialise the trace output channel.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">tracer&lt;T&gt;::initialise()</a>. Called during startup to enable the trace channel.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00236">236</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga2eeb0c01fc5d6e432e319950a94acb2c">236</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga2eeb0c01fc5d6e432e319950a94acb2c">initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">237</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">238</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">detail::tracer&lt;detail::implementation&gt;::initialise</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">239</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">micro_os_plus::trace::detail::tracer&lt; T &gt;::initialise</a>.</p>

</div>
</div>

### write() {#gacfbedd8169716b02026a93c948af99c8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">ssize_t micro_os_plus::trace::write (const void * buf, std::size_t nbyte)</td>
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

<p>Write the given number of bytes to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">buf</td>
<td class="doxyParamItemDescription"><p>An array of bytes.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">nbyte</td>
<td class="doxyParamItemDescription"><p>The number of bytes in the array.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The number of bytes actually written, or -1 if error.</p></dd>
</dl>


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">tracer&lt;T&gt;::write()</a>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00242">242</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gacfbedd8169716b02026a93c948af99c8">242</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gacfbedd8169716b02026a93c948af99c8">write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t nbyte) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">243</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">244</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">detail::tracer&lt;detail::implementation&gt;::write</a> (buf, nbyte);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">245</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">micro_os_plus::trace::detail::tracer&lt; T &gt;::write</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">micro_os_plus::trace::detail::tracer&lt; T &gt;::putchar</a>, <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">micro_os_plus::trace::detail::tracer&lt; T &gt;::puts</a> and <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
