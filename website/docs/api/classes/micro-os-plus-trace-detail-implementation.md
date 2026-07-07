---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/trace/detail/implementation
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `implementation` Class

<p>Policy class for the production trace instance. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::trace::detail::implementation { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">micro-os-plus/diag/trace.h</a>&gt;
</div>

## Public Static Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab6bc9c127091ba107f059b83a932a590">flush</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="#ab6bc9c127091ba107f059b83a932a590">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a85bfae1a60141a8c5df3017e47158fc6">initialise</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="#a85bfae1a60141a8c5df3017e47158fc6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">static ssize_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a883b0bd506d3612ecf84d1ad604e5949">write</a> (const void *buf, std::size_t nbyte) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="#a883b0bd506d3612ecf84d1ad604e5949">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Policy class for the production trace instance.</p>


<p>The user must provide a definition of <span class="doxyComputerOutput"><a href="#a85bfae1a60141a8c5df3017e47158fc6">initialise()</a></span>, <span class="doxyComputerOutput"><a href="#a883b0bd506d3612ecf84d1ad604e5949">write()</a></span>, and <span class="doxyComputerOutput"><a href="#ab6bc9c127091ba107f059b83a932a590">flush()</a></span> for this class (typically in a single .cpp file, once per application/platform).</p>


<p><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a></span> is not a template; it has no member data and is never instantiated as an object. Its static methods are looked up by <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer</a>&lt;<a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a>&gt;</span> and are otherwise ordinary, non-template member functions, so there is no instantiation-order hazard between their declaration here and their definition elsewhere.</p>


<p>Definition at line 289 of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h">trace-cpp-api.h</a>.</p>


<div class="doxySectionDef">

## Public Static Functions

### flush() {#ab6bc9c127091ba107f059b83a932a590}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::detail::implementation::flush (void)</td>
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

<p>Flush the trace output channel.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The user must provide a definition of this method. For buffered output channels, it must drain any internally buffered data to the output device. For unbuffered or character-mode channels (e.g. ITM), the body can be left empty.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h/#l00338">338</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h">trace-cpp-api.h</a>.</p>

</div>
</div>

### initialise() {#a85bfae1a60141a8c5df3017e47158fc6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::trace::detail::implementation::initialise (void)</td>
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

<p>Initialise the trace output channel.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>The user must provide a definition of this method, called once during startup to configure the underlying output device (e.g. a semihosting channel, or ITM port).</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h/#l00305">305</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h">trace-cpp-api.h</a>.</p>

</div>
</div>

### write() {#a883b0bd506d3612ecf84d1ad604e5949}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">ssize_t micro_os_plus::trace::detail::implementation::write (const void * buf, std::size_t nbyte)</td>
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
<dd><p>The number of bytes actually transferred, or -1 if error. May be less than <span class="doxyComputerOutput">nbyte</span> if the device is full.</p></dd>
</dl>


<p>The user must provide a definition of this method. It is the core output primitive; all higher-level functions (<span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a></span>, <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">puts</a></span>, <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a></span>) ultimately delegate to it.</p>


<p>Definition at line <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h/#l00321">321</a> of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h">trace-cpp-api.h</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following file:

<ul>
<li><a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-cpp-api-h">trace-cpp-api.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
