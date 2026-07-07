---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/diag/trace-cpp-api-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `trace-cpp-api.h` File

<p>C++ header file with the declarations for the C++ trace API. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include &lt;sys/types.h&gt;
#include &lt;cstddef&gt;
#include &lt;cstdarg&gt;
#include &lt;concepts&gt;
#include "<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/inlines/trace-cpp-api-inlines-h">inlines/trace-cpp-api-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">trace</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Tracing support namespace. <a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

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

<p>C++ header file with the declarations for the C++ trace API.</p>


<p>Declarations for the <span class="doxyComputerOutput">tracer</span> class template and the <span class="doxyComputerOutput">trace_policy</span> concept.</p>


<p>Inline method definitions are located in <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/inlines/trace-cpp-api-inlines-h">trace-cpp-api-inlines.h</a>, included at the bottom of this file. This file is included by <span class="doxyComputerOutput">&lt;<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">micro-os-plus/diag/trace.h</a>&gt;</span>, which should be used instead of including this file directly.</p>


## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * for any purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * be obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00028"></a>28</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00029"></a>29</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00030"></a>30</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00031"></a>31</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00032"></a>32</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#error "Do not include this file directly; use &lt;micro-os-plus/diag/trace.h&gt;."</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00033"></a>33</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_DIAG_TRACE_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00034"></a>34</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00035"></a>35</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00036"></a>36</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00037"></a>37</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00038"></a>38</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00039"></a>39</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00040"></a>40</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00041"></a>41</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;sys/types.h&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightComment">// #include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstddef&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdarg&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span><span class="doxyLineContent"><span class="doxyHighlightComment">// #include &lt;cstdlib&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;concepts&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wpre-c++17-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00103"></a>103</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00104"></a>104</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">micro_os_plus::trace</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00105"></a>105</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00107"></a>107</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00108"></a>108</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00109"></a>109</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00110"></a>110</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00111"></a>111</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00112"></a>112</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// Free functions declarations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00113"></a>113</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00128"></a>128</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00129"></a>129</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#ga2eeb0c01fc5d6e432e319950a94acb2c">initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00130"></a>130</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00143"></a>143</span><span class="doxyLineContent"><span class="doxyHighlight">  ssize_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00144"></a>144</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gacfbedd8169716b02026a93c948af99c8">write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t nbyte) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00145"></a>145</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00158"></a>158</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-implementation/#gad2196053624765f72c82e983d6d3e512">flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00160"></a>160</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00161"></a>161</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00162"></a>162</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a>176</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00192"></a>192</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00193"></a>193</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">vprintf</a> (const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, std::va_list arguments) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00194"></a>194</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00207"></a>207</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00208"></a>208</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">puts</a> (const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00209"></a>209</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00222"></a>222</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00223"></a>223</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00224"></a>224</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00240"></a>240</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a>241</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name = </span><span class="doxyHighlightStringLiteral">"main"</span><span class="doxyHighlight">) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::trace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00247"></a>247</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00248"></a>248</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00249"></a>249</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00250"></a>250</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00251"></a>251</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00252"></a>252</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace">micro_os_plus::trace</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00253"></a>253</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00254"></a>254</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00255"></a>255</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00260"></a>260</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00273"></a>273</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00274"></a>274</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00289"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">289</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation">implementation</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a>290</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a85bfae1a60141a8c5df3017e47158fc6">305</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a85bfae1a60141a8c5df3017e47158fc6">initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00306"></a>306</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00320"></a>320</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> ssize_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00321"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a883b0bd506d3612ecf84d1ad604e5949">321</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#a883b0bd506d3612ecf84d1ad604e5949">write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t nbyte) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00322"></a>322</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00337"></a>337</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00338"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#ab6bc9c127091ba107f059b83a932a590">338</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/implementation/#ab6bc9c127091ba107f059b83a932a590">flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00341"></a>341</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00342"></a>342</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00360"></a>360</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00361"></a><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">361</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/concepts/micro-os-plus/trace/detail/trace-policy">trace_policy</a> = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, std::size_t n) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00362"></a>362</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::initialise () } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;void&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00363"></a>363</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::write (buf, n) } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;ssize_t&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00364"></a>364</span><span class="doxyLineContent"><span class="doxyHighlight">      { T::flush () } </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; std::same_as&lt;void&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00365"></a>365</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00366"></a>366</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a>367</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00368"></a>368</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00390"></a>390</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;trace_policy T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00391"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">391</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7db5bf09d5a4b1b7732dba2477013bc4">tracer</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00392"></a>392</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00393"></a>393</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00402"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7db5bf09d5a4b1b7732dba2477013bc4">402</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7db5bf09d5a4b1b7732dba2477013bc4">tracer</a> () = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00403"></a>403</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00419"></a>419</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00420"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa71a6a7f9d9378f02c48aea3c0d0de90">420</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa71a6a7f9d9378f02c48aea3c0d0de90">initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (T::initialise ()))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00421"></a>421</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00422"></a>422</span><span class="doxyLineContent"><span class="doxyHighlight">        T::initialise ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00423"></a>423</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> ssize_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a88600a0485aa9c9afa7f306d2a298fdb">440</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a88600a0485aa9c9afa7f306d2a298fdb">write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00441"></a>441</span><span class="doxyLineContent"><span class="doxyHighlight">             std::size_t nbyte) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (T::write (buf, nbyte)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> T::write (buf, nbyte);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a>444</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00445"></a>445</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00463"></a>463</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00464"></a><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7c2ce977002993a65bd74ca011f1615f">464</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7c2ce977002993a65bd74ca011f1615f">flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> (T::flush ()))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00465"></a>465</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00466"></a>466</span><span class="doxyLineContent"><span class="doxyHighlight">        T::flush ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00467"></a>467</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00468"></a>468</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00469"></a>469</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00470"></a>470</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a>485</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00486"></a>486</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a7fb471958c000ac75290f5cc68522953">printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...) noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00487"></a>487</span><span class="doxyLineContent"><span class="doxyHighlight">          __attribute__ ((format (<a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga1147fe38ae648cb84a4e668cf68c405b">printf</a>, 1, 2)));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00488"></a>488</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00506"></a>506</span><span class="doxyLineContent"><span class="doxyHighlight">      static </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00507"></a>507</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#gafb94817670ea90990b925e71d14ef910">vprintf</a> (const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, std::va_list arguments) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00508"></a>508</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00523"></a>523</span><span class="doxyLineContent"><span class="doxyHighlight">      static </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00524"></a>524</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga35f7d251803f518a84162208e8165d0a">puts</a> (const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s = </span><span class="doxyHighlightStringLiteral">""</span><span class="doxyHighlight">) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00525"></a>525</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00537"></a>537</span><span class="doxyLineContent"><span class="doxyHighlight">      static </span><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00538"></a>538</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-main/#ga8b4745ad9d5b6a65f95f40e70acc518a">putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00539"></a>539</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00557"></a>557</span><span class="doxyLineContent"><span class="doxyHighlight">      static </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00558"></a>558</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-cpp-api-extra/#gad5ebcf3eebf3239a2f572f8640a94c90">dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[], const </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name = </span><span class="doxyHighlightStringLiteral">"main"</span><span class="doxyHighlight">) noexcept;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00559"></a>559</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00560"></a>560</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00561"></a>561</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00562"></a>562</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Suppress implicit instantiation of the tracer member function bodies</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00563"></a>563</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// in every TU that includes this header. The explicit instantiations in</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00564"></a>564</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// trace.cpp are the sole ODR-defining instances.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a>565</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00566"></a>566</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00567"></a>567</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00568"></a>568</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00569"></a>569</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00570"></a>570</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00571"></a>571</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00572"></a>572</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">extern</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer">tracer&lt;implementation&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00573"></a>573</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00574"></a>574</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00575"></a>575</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00576"></a>576</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00577"></a>577</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00578"></a>578</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::trace</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00579"></a>579</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00580"></a>580</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00581"></a>581</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00582"></a>582</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00583"></a>583</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00584"></a>584</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00585"></a>585</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00586"></a>586</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00587"></a>587</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a>588</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00589"></a>589</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00590"></a>590</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00591"></a>591</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00592"></a>592</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00593"></a>593</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00594"></a>594</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00595"></a>595</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/inlines/trace-cpp-api-inlines-h">inlines/trace-cpp-api-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00596"></a>596</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00597"></a>597</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00598"></a>598</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00599"></a>599</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00600"></a>600</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00601"></a>601</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
