---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/trace/detail/tracer
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `tracer` Class Template

<p>Tracing API bound to a given policy class. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;trace_policy T&gt;<br/>
class micro_os_plus::trace::detail::tracer&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">micro-os-plus/diag/trace.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#a7db5bf09d5a4b1b7732dba2477013bc4">tracer</a> ()=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted default constructor. <a href="#a7db5bf09d5a4b1b7732dba2477013bc4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a4e2e2a73a7ec36ac69d94840eb0b52e2">dump_args</a> (int argc, char *argv[], const char *name="main") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Send the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel. <a href="#a4e2e2a73a7ec36ac69d94840eb0b52e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aca35e085ab85a4e69a6ef41178871484">flush</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="#aca35e085ab85a4e69a6ef41178871484">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0d039b1f2025b3ce6178d4394a785728">initialise</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="#a0d039b1f2025b3ce6178d4394a785728">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static int</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7fb471958c000ac75290f5cc68522953">printf</a> (const char *format,...) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted string to the trace output channel. <a href="#a7fb471958c000ac75290f5cc68522953">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static int</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ad0af55a735d06c5c25c8bf38dc3fd4fd">putchar</a> (int c) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the single character to the trace output channel. <a href="#ad0af55a735d06c5c25c8bf38dc3fd4fd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static int</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a2f7941dcb7ddb9f6afd664ad0c1c9979">puts</a> (const char *s="") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the string and a line terminator to the trace output channel. <a href="#a2f7941dcb7ddb9f6afd664ad0c1c9979">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static int</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a4176d29127dbd89ba01a79770808d094">vprintf</a> (const char *format, std::va_list arguments) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted variable arguments list to the trace output channel. <a href="#a4176d29127dbd89ba01a79770808d094">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;trace_policy T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">static ssize_t</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">write</a> (const void *buf, std::size_t nbyte) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Tracing API bound to a given policy class.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>Policy class providing the static <span class="doxyComputerOutput"><a href="#a0d039b1f2025b3ce6178d4394a785728">initialise()</a></span>, <span class="doxyComputerOutput"><a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">write()</a></span>, and <span class="doxyComputerOutput"><a href="#aca35e085ab85a4e69a6ef41178871484">flush()</a></span> primitives (e.g. <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">micro_os_plus::trace::detail::implementation</a>).</p></td>
</tr>
</table>
</dd>
</dl>

<p>All methods are static; <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer</a></span> is never instantiated as an object. Each distinct <span class="doxyComputerOutput">T</span> produces an independent set of methods with no shared state, so <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer</a>&lt;<a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a>&gt;</span> (or any further user-defined policy class) can coexist in the same translation unit and binary.</p>


<p>The main reason for using a class template rather than a namespace is that it allows the policy class to be a template parameter, so that multiple independent instances can coexist in the same binary, each bound to a different policy class. This is used in testing, where a <span class="doxyComputerOutput">testing_implementation</span> policy class is defined to capture the output for verification.</p>


<p>Definition at line 403 of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### tracer() {#a7db5bf09d5a4b1b7732dba2477013bc4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::trace::detail::tracer&lt; T &gt;::tracer ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted default constructor.</p>


<p><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer</a></span> is a purely static utility class; all methods are static and no instance is ever created. The default constructor is explicitly deleted to enforce this intent and prevent accidental instantiation.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00414">414</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Static Functions

### dump\_args() {#a4e2e2a73a7ec36ac69d94840eb0b52e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::detail::tracer&lt; T &gt;::dump_args (int argc, char * argv=[], const char * name="main")</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Formats and writes the argument list in the form <span class="doxyComputerOutput">name(argc=N, argv=["arg0", "arg1", ...])</span>, followed by a newline. Intended to be called at the start of <span class="doxyComputerOutput">main()</span> to record the process arguments in the trace output. Each argument string is quoted; no escaping is applied to the string content.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00573">573</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00210">210</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4e2e2a73a7ec36ac69d94840eb0b52e2">210</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4e2e2a73a7ec36ac69d94840eb0b52e2">tracer&lt;T&gt;::dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightStringLiteral">"%s(argc=%d, argv=["</span><span class="doxyHighlight">, name, argc);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> i = 0; i &lt; argc; ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i != 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">216</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">217</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightStringLiteral">", "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">219</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightStringLiteral">"\"%s\""</span><span class="doxyHighlight">, argv[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">220</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">221</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightStringLiteral">"])\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">222</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">micro_os_plus::trace::printf</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">micro_os_plus::trace::dump_args</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra/#ga49bd9637ae06ff570445fbc6830f19a7">micro_os_plus_trace_dump_args</a>.</p>

</div>
</div>

### flush() {#aca35e085ab85a4e69a6ef41178871484}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::detail::tracer&lt; T &gt;::flush (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Delegates unconditionally to <span class="doxyComputerOutput">T::flush()</span>.</p>


<p>For buffered output channels, the policy method must drain any internally buffered data to the output device. For unbuffered or character-mode channels (e.g. ITM), the policy method body can be left empty. Unconditionally <span class="doxyComputerOutput">noexcept</span>, since the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a></span> concept already requires <span class="doxyComputerOutput">T::flush()</span> to be <span class="doxyComputerOutput">noexcept</span>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00477">477</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aca35e085ab85a4e69a6ef41178871484">477</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#aca35e085ab85a4e69a6ef41178871484">flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">479</span><span class="doxyLineContent"><span class="doxyHighlight">        T::flush ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>

</div>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gad2196053624765f72c82e983d6d3e512">micro_os_plus::trace::flush</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#gac34c391936f919c141bc38ec5b5a1db9">micro_os_plus_trace_flush</a>.</p>

</div>
</div>

### initialise() {#a0d039b1f2025b3ce6178d4394a785728}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::detail::tracer&lt; T &gt;::initialise (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Delegates unconditionally to <span class="doxyComputerOutput">T::initialise()</span>.</p>


<p>Called during startup, as early as possible, to enable the trace channel. Unconditionally <span class="doxyComputerOutput">noexcept</span>, since the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a></span> concept already requires <span class="doxyComputerOutput">T::initialise()</span> to be <span class="doxyComputerOutput">noexcept</span>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00432">432</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0d039b1f2025b3ce6178d4394a785728">432</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#a0d039b1f2025b3ce6178d4394a785728">initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">        T::initialise ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>

</div>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#ga2eeb0c01fc5d6e432e319950a94acb2c">micro_os_plus::trace::initialise</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga425f36ab6d5a58a63bc926f4675dc53b">micro_os_plus_trace_initialise</a>.</p>

</div>
</div>

### printf() {#a7fb471958c000ac75290f5cc68522953}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::detail::tracer&lt; T &gt;::printf (const char * format, ...)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Formatting is performed into a fixed-size stack buffer of <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#ga2084a7003aa78ca9574f96fcb9b5ff4e">MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER</a></span> bytes (default: 200). Output that exceeds this limit is silently truncated before being passed to <span class="doxyComputerOutput"><a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">write()</a></span>. The return value reflects the bytes actually written, not the number that the format string would have produced; it cannot be used to detect whether truncation occurred.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00500">500</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00076">76</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7fb471958c000ac75290f5cc68522953">76</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a7fb471958c000ac75290f5cc68522953">tracer&lt;T&gt;::printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">77</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">78</span><span class="doxyLineContent"><span class="doxyHighlight">      std::va_list arguments;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">79</span><span class="doxyLineContent"><span class="doxyHighlight">      va_start (arguments, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">80</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ret = <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">      va_end (arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> ret;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">micro_os_plus::trace::vprintf</a>.</p>

</div>
</div>

### putchar() {#ad0af55a735d06c5c25c8bf38dc3fd4fd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::detail::tracer&lt; T &gt;::putchar (int c)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Converts <span class="doxyComputerOutput">c</span> to <span class="doxyComputerOutput">unsigned char</span> and passes it as a one-byte buffer to <span class="doxyComputerOutput"><a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">write()</a></span>. On success, returns the original value of <span class="doxyComputerOutput">c</span>; on failure, returns EOF.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00553">553</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00186">186</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad0af55a735d06c5c25c8bf38dc3fd4fd">186</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ad0af55a735d06c5c25c8bf38dc3fd4fd">tracer&lt;T&gt;::putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> ch = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">      ssize_t ret = <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (&amp;ch, 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ret &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> c;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> EOF;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">micro_os_plus::trace::write</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">micro_os_plus::trace::putchar</a>.</p>

</div>
</div>

### puts() {#a2f7941dcb7ddb9f6afd664ad0c1c9979}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::detail::tracer&lt; T &gt;::puts (const char * s="")</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Writes the characters of <span class="doxyComputerOutput">s</span> followed by a single newline character (<span class="doxyComputerOutput">'\n'</span>). Unlike the standard C <span class="doxyComputerOutput"><a href="#a2f7941dcb7ddb9f6afd664ad0c1c9979">puts()</a></span>, this function returns the total byte count written. If writing the newline fails after the string has been written successfully, EOF is returned.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00539">539</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00141">141</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a2f7941dcb7ddb9f6afd664ad0c1c9979">141</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a2f7941dcb7ddb9f6afd664ad0c1c9979">tracer&lt;T&gt;::puts</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t len = std::strlen (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">      ssize_t ret = <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (s, len);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Only append the line terminator if the string was written in</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// full; a partial write (including a zero-byte write, which is</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// not itself an error) must not be followed by a bare newline.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ret &gt;= 0 &amp;&amp; </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">std::size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (ret) == len)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">          ssize_t ret2 = <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">, 1); </span><span class="doxyHighlightComment">// Add a line terminator</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ret2 &lt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">              ret = ret2; </span><span class="doxyHighlightComment">// Propagate the error.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">              ret += ret2; </span><span class="doxyHighlightComment">// Return total bytes written.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ret &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wuseless-cast"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Cast required on 64-bit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (ret);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">175</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> EOF;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">micro_os_plus::trace::write</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">micro_os_plus::trace::puts</a>.</p>

</div>
</div>

### vprintf() {#a4176d29127dbd89ba01a79770808d094}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::trace::detail::tracer&lt; T &gt;::vprintf (const char * format, std::va_list arguments)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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
<dd><p>The number of bytes written to the output channel, or -1 if an error occurred.</p></dd>
</dl>


<p>Equivalent to <span class="doxyComputerOutput"><a href="#a7fb471958c000ac75290f5cc68522953">printf()</a></span>, but accepts a <span class="doxyComputerOutput">std::va_list</span> instead of a variadic argument list. Subject to the same fixed-size stack buffer constraint. When the formatted output exceeds the buffer size, the text is truncated silently; the return value then reflects the bytes actually written to the channel, not the total length that <span class="doxyComputerOutput">vsnprintf</span> would have produced, and cannot be used to detect whether truncation occurred. Typically called by <span class="doxyComputerOutput"><a href="#a7fb471958c000ac75290f5cc68522953">printf()</a></span>.</p>


<p>Declaration at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00522">522</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>, definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h/#l00089">89</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4176d29127dbd89ba01a79770808d094">89</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4176d29127dbd89ba01a79770808d094">tracer&lt;T&gt;::vprintf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, std::va_list arguments) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Caution: allocated on the stack!</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> buf[<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#ga2084a7003aa78ca9574f96fcb9b5ff4e">MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER</a>];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// TODO: possibly rewrite it to no longer use newlib,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// (although the nano version is no longer very heavy).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wformat-nonliteral"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Print to the local buffer</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">      ssize_t ret = ::vsnprintf (buf, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buf), format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ret &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Clamp to actual buffer size if output was truncated.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Note: on truncation the return value becomes the byte count</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// written to the channel, not the total length vsnprintf</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// computed. Callers cannot use the return value to detect</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// truncation.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">          ret = <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (buf,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">                       </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (std::min (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">                           ret, </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlight">ssize_t</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buf) - 1))));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wuseless-cast"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Cast required on 64-bit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (ret);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#ga2084a7003aa78ca9574f96fcb9b5ff4e">MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">micro_os_plus::trace::write</a>.</p>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a>, <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga61e826d87556c899edad6f82d7bd36ef">micro_os_plus_trace_vprintf</a>, <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">micro_os_plus::trace::printf</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">micro_os_plus::trace::vprintf</a>.</p>

</div>
</div>

### write() {#aa2d6c80ffc49710b88ba91e0c0d6e503}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;trace_policy T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">ssize_t micro_os_plus::trace::detail::tracer&lt; T &gt;::write (const void * buf, std::size_t nbyte)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
<span class="doxyMemberLabel static">static</span>
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


<p>Delegates unconditionally to <span class="doxyComputerOutput">T::write()</span>.</p>


<p>The return value must reflect the number of bytes actually transferred; a return value of -1 signals an error. Unconditionally <span class="doxyComputerOutput">noexcept</span>, since the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a></span> concept already requires <span class="doxyComputerOutput">T::write()</span> to be <span class="doxyComputerOutput">noexcept</span>.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h/#l00453">453</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">453</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#aa2d6c80ffc49710b88ba91e0c0d6e503">write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t nbyte) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> T::write (buf, nbyte);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>

</div>


<p>Referenced by <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a> and <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">micro_os_plus::trace::write</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a></li>
<li><a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/cpp-api-inlines-h">cpp-api-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
