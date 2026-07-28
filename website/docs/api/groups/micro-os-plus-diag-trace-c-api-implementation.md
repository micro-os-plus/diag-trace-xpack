---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-c-api-implementation
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Implementation functions

<p>C wrappers for the user-supplied back-end primitives. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gac34c391936f919c141bc38ec5b5a1db9">micro_os_plus_trace_flush</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="#gac34c391936f919c141bc38ec5b5a1db9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga425f36ab6d5a58a63bc926f4675dc53b">micro_os_plus_trace_initialise</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="#ga425f36ab6d5a58a63bc926f4675dc53b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">ssize_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a> (const void *buf, size_t nbyte)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="#ga80d104ecf38dfcf40cae10bac0d2c562">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C wrappers for the user-supplied back-end primitives.</p>


<p>These functions may be invoked from C projects to execute actions specific to the implementation.</p>


<div class="doxySectionDef">

## Functions

### micro\_os\_plus\_trace\_flush() {#gac34c391936f919c141bc38ec5b5a1db9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus_trace_flush (void)</td>
</tr>
</table>
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


<p>For buffered output channels, this function must drain any internally buffered data to the output device. For unbuffered or character-mode channels (e.g. ITM), the body can be left empty. No assumptions are made about thread safety or re-entrancy; the caller is responsible for ensuring that concurrent calls do not occur.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h/#l00110">110</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00058">58</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gac34c391936f919c141bc38ec5b5a1db9">58</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#gac34c391936f919c141bc38ec5b5a1db9">micro_os_plus_trace_flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">59</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">60</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">detail::tracer&lt;detail::implementation&gt;::flush</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">61</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">micro_os_plus::trace::detail::tracer&lt; T &gt;::flush</a>.</p>

</div>
</div>

### micro\_os\_plus\_trace\_initialise() {#ga425f36ab6d5a58a63bc926f4675dc53b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus_trace_initialise (void)</td>
</tr>
</table>
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


<p>This function is called during startup, as early as possible, to enable the trace channel. The user must provide a definition of this function that configures the underlying output device (e.g. a semihosting channel, or an ITM port).</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h/#l00071">71</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00046">46</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga425f36ab6d5a58a63bc926f4675dc53b">46</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga425f36ab6d5a58a63bc926f4675dc53b">micro_os_plus_trace_initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">47</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">48</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">detail::tracer&lt;detail::implementation&gt;::initialise</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">49</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">micro_os_plus::trace::detail::tracer&lt; T &gt;::initialise</a>.</p>

</div>
</div>

### micro\_os\_plus\_trace\_write() {#ga80d104ecf38dfcf40cae10bac0d2c562}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">ssize_t micro_os_plus_trace_write (const void * buf, size_t nbyte)</td>
</tr>
</table>
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


<p>This is the core output primitive. The user must provide a definition of this function. The return value must reflect the number of bytes actually transferred to the output device, which may be less than <span class="doxyComputerOutput">nbyte</span> if the device is full or an error occurs. A return value of -1 signals an error; any non-negative value is treated as a byte count by the higher-level functions.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h/#l00090">90</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00052">52</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga80d104ecf38dfcf40cae10bac0d2c562">52</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> nbyte)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">53</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">54</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">detail::tracer&lt;detail::implementation&gt;::write</a> (buf, nbyte);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">55</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">micro_os_plus::trace::detail::tracer&lt; T &gt;::write</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
