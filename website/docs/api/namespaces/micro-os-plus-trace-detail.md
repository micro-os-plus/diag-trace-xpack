---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/namespaces/micro-os-plus/trace/detail
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - namespace

---

<div class="doxyPage">

# `detail` Namespace

<p>Implementation details namespace. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
namespace micro_os_plus::trace::detail { ... }
</div>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Policy class for the production trace instance. <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer&lt;T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Tracing API bound to a given policy class. <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Concepts Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Concept constraining the policy class <span class="doxyComputerOutput">T</span> used by <span class="doxyComputerOutput">tracer&lt;T&gt;</span>. <a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Implementation details namespace.</p>


<p>The <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail">detail</a></span> namespace contains internal implementation components that are not part of the public API. It houses the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer</a></span> class template and the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a></span> policy class, along with the <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a></span> concept used to constrain policy types.</p>


<p>User code should not reference this namespace directly. The public interface is the set of free functions in the enclosing <span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">micro_os_plus::trace</a></span> namespace.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
