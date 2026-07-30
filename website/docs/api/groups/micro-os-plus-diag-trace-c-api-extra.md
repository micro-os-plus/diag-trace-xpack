---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-c-api-extra
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Utility functions

<p>Supplementary C trace utility functions. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga49bd9637ae06ff570445fbc6830f19a7">micro_os_plus_trace_dump_args</a> (int argc, char *argv[])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel. <a href="#ga49bd9637ae06ff570445fbc6830f19a7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Supplementary C trace utility functions.</p>


<p>These are supplementary functions designed to enhance tracing capabilities.</p>


<div class="doxySectionDef">

## Functions

### micro\_os\_plus\_trace\_dump\_args() {#ga49bd9637ae06ff570445fbc6830f19a7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus_trace_dump_args (int argc, char * argv=[])</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Write the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">argc</td>
<td class="doxyParamItemDescription"><p>The number of <span class="doxyComputerOutput">argv[]</span> strings.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">argv</td>
<td class="doxyParamItemDescription"><p>An array of pointers to argument strings.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Formats and writes the argument list in the form <span class="doxyComputerOutput">main(argc=N, argv=["arg0", "arg1", ...])</span>, followed by a newline. The prefix is always the literal string <span class="doxyComputerOutput">"main"</span>; for a configurable prefix, use the C++ API <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">micro_os_plus::trace::dump_args()</a></span>. Intended to be called at the start of <span class="doxyComputerOutput">main()</span> to record the process arguments in the trace output. Each argument string is quoted; no escaping is applied to the string content.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h/#l00208">208</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp/#l00112">112</a> of file <a href="/diag-trace-xpack/docs/api/files/src/trace-c-api-cpp">trace-c-api.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga49bd9637ae06ff570445fbc6830f19a7">112</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="#ga49bd9637ae06ff570445fbc6830f19a7">micro_os_plus_trace_dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">detail::tracer&lt;detail::implementation&gt;::dump_args</a> (argc, argv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">micro_os_plus::trace::detail::tracer&lt; T &gt;::dump_args</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
