---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/trace/detail/trace-policy
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `trace_policy` Concept

<p>Concept constraining the policy class <span class="doxyComputerOutput">T</span> used by <span class="doxyComputerOutput">tracer&lt;T&gt;</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;typename T&gt;<br/>
concept <a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">micro_os_plus::trace::detail::trace_policy</a> =  requires (const void* buf, std::size_t n) {<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{ T::initialise () } noexcept -&gt; std::same_as&lt;void&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{ T::write (buf, n) } noexcept -&gt; std::same_as&lt;ssize_t&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{ T::flush () } noexcept -&gt; std::same_as&lt;void&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;}
</div>

## Description {#details}

<p>Concept constraining the policy class <span class="doxyComputerOutput">T</span> used by <span class="doxyComputerOutput">tracer&lt;T&gt;</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The policy class to be constrained.</p></td>
</tr>
</table>
</dd>
</dl>

<p>A conforming <span class="doxyComputerOutput">T</span> must expose three static, <span class="doxyComputerOutput">noexcept</span> member functions with the following exact signatures:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">static void T::initialise() noexcept</span></li>
<li><span class="doxyComputerOutput">static ssize_t T::write(const void*, std::size_t) noexcept</span></li>
<li><span class="doxyComputerOutput">static void T::flush() noexcept</span></li>
</ul>

<p>The <span class="doxyComputerOutput">noexcept</span> requirement is enforced by the concept so that a non-conforming policy is rejected at instantiation time rather than silently invoking <span class="doxyComputerOutput">std::terminate</span> through the unconditionally <span class="doxyComputerOutput">noexcept</span> free-function wrappers. A clear diagnostic is emitted at the point of instantiation if any required function is absent, has the wrong signature, or is not <span class="doxyComputerOutput">noexcept</span>.</p>


<p>Definition at line 370 of file <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/cpp-api-h">cpp-api.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">trace_policy = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t n) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::initialise () } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;void&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::write (buf, n) } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;ssize_t&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::flush () } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;void&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
