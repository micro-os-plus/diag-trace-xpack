---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/trace
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `trace` Namespace

<p>Tracing support namespace. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::trace { ... }
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Implementation details namespace. <a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">dump_args</a> (int argc, char *argv[], const char *name="main") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Send the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gad2196053624765f72c82e983d6d3e512">flush</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gad2196053624765f72c82e983d6d3e512">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#ga2eeb0c01fc5d6e432e319950a94acb2c">initialise</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#ga2eeb0c01fc5d6e432e319950a94acb2c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (const char *format,...) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted string to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a> (int c) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the single character to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">puts</a> (const char *s="") noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the string and a line terminator to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">vprintf</a> (const char *format, std::va_list arguments) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted variable arguments list to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">ssize_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (const void *buf, std::size_t nbyte) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Tracing support namespace.</p>


<p>The trace channel functions as a standalone output device designed specifically for diagnostic purposes.</p>


<p>The API is straightforward and emulates the standard C output calls:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">micro_os_plus::trace::printf()</a></span> / <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf()</a></span></li>
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">micro_os_plus::trace::puts()</a></span> / <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts()</a></span></li>
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">micro_os_plus::trace::putchar()</a></span> / <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar()</a></span></li>
</ul>

<p>The C++ API is implemented as a class template, <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">micro_os_plus::trace::detail::tracer</a></span>, parameterised on a policy class that supplies the low-level primitives. One such policy class is declared here: <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">micro_os_plus::trace::detail::implementation</a></span> for production use. <span class="doxyComputerOutput">tracer&lt;implementation&gt;</span> is an independent class instantiation: it is already instantiated and is used internally; it shares no mutable state.</p>


<p>The free functions (<span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">micro_os_plus::trace::printf()</a></span> etc.) are a thin alias for <span class="doxyComputerOutput">tracer&lt;implementation&gt;</span>, so existing call sites do not need to change.</p>


<p>The user is required to provide implementations of the following static methods, once per policy class actually used:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a85bfae1a60141a8c5df3017e47158fc6">micro_os_plus::trace::detail::implementation::initialise()</a></span></li>
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a883b0bd506d3612ecf84d1ad604e5949">micro_os_plus::trace::detail::implementation::write()</a></span></li>
<li><span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#ab6bc9c127091ba107f059b83a932a590">micro_os_plus::trace::detail::implementation::flush()</a></span></li>
</ul>

<p>Trace support is activated by adding the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#gac21aa3324300f25da16bf17b95afbd90">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</a></span> macro definition to the <span class="doxyComputerOutput">micro-os-plus/diag/trace-defines.h</span> file.</p>


<p>When <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-config/#gac21aa3324300f25da16bf17b95afbd90">MICRO_OS_PLUS_DIAG_TRACE_ENABLED</a></span> is not defined, all functions are inlined to empty bodies. This approach eliminates the need for trace calls to be conditionally compiled using <span class="doxyComputerOutput">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span> and <span class="doxyComputerOutput">#endif</span>. However, the drawback is that the associated header file must always be included.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
