---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-diag-trace-cpp-api-extra
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Utility functions

<p>Supplementary C++ trace utility functions. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gad5ebcf3eebf3239a2f572f8640a94c90">dump_args</a> (int argc, char *argv[], const char *name="main") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Send the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel. <a href="#gad5ebcf3eebf3239a2f572f8640a94c90">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Supplementary C++ trace utility functions.</p>


<p>These are supplementary functions designed to enhance tracing capabilities.</p>


<div class="doxySectionDef">

## Functions

### dump\_args() {#gad5ebcf3eebf3239a2f572f8640a94c90}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::dump_args (int argc, char * argv=[], const char * name="main")</td>
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

<p>Send the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel.</p>


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
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>A null terminated string used as the function name prefix (default: <span class="doxyComputerOutput">"main"</span>).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Thin wrapper over <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">tracer&lt;T&gt;::dump_args()</a>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00285">285</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gad5ebcf3eebf3239a2f572f8640a94c90">285</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gad5ebcf3eebf3239a2f572f8640a94c90">dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">detail::tracer&lt;detail::implementation&gt;::dump_args</a> (argc, argv, name);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">micro_os_plus::trace::detail::tracer&lt; T &gt;::dump_args</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
