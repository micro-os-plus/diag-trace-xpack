---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/src/trace-c-api-cpp
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `trace-c-api.cpp` File

<p>C++ source file with the definitions for the C trace API. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">micro-os-plus/diag/trace.h</a>"
</div>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra/#ga49bd9637ae06ff570445fbc6830f19a7">micro_os_plus_trace_dump_args</a> (int argc, char *argv[])</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the <span class="doxyComputerOutput">argv[]</span> array to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra/#ga49bd9637ae06ff570445fbc6830f19a7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#gac34c391936f919c141bc38ec5b5a1db9">micro_os_plus_trace_flush</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#gac34c391936f919c141bc38ec5b5a1db9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga425f36ab6d5a58a63bc926f4675dc53b">micro_os_plus_trace_initialise</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga425f36ab6d5a58a63bc926f4675dc53b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a> (const char *format,...)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted string to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar</a> (int c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the single character to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the string and a line terminator to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga61e826d87556c899edad6f82d7bd36ef">micro_os_plus_trace_vprintf</a> (const char *format, va_list arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write a formatted variable arguments list to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga61e826d87556c899edad6f82d7bd36ef">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">ssize_t</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a> (const void *buf, size_t nbyte)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Write the given number of bytes to the trace output channel. <a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ source file with the definitions for the C trace API.</p>


<p>Definitions for the C-linkage wrapper functions (<span class="doxyComputerOutput"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf()</a></span>, etc.) that forward to the corresponding C++ internal <span class="doxyComputerOutput">tracer&lt;implementation&gt;</span> functions.</p>


<p>The empty inline stubs (used when tracing is disabled) are located in <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/inlines/c-api-inlines-h">c-api-inlines.h</a>, included at the bottom of <a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace/c-api-h">c-api.h</a>.</p>


## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00027"></a>27</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00028"></a>28</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00029"></a>29</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00030"></a>30</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/diag-trace-xpack/docs/api/files/include/micro-os-plus/diag/trace-h">micro-os-plus/diag/trace.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00031"></a>31</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00032"></a>32</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00033"></a>33</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00034"></a>34</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00035"></a>35</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00036"></a>36</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00037"></a>37</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00038"></a>38</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00039"></a>39</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00040"></a>40</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00041"></a>41</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail">detail</a> = <a href="/diag-trace-xpack/docs/api/namespaces/micro-os-plus/trace/detail">micro_os_plus::trace::detail</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span><span class="doxyLineContent"><span class="doxyHighlightComment">// The C API is always bound to the `tracer&lt;implementation&gt;` policy class;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span><span class="doxyLineContent"><span class="doxyHighlightComment">// extern "C" does not support templates, so it cannot expose other</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightComment">// instances. Code that needs custom instances must call the C++</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span><span class="doxyLineContent"><span class="doxyHighlightComment">// API directly.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga425f36ab6d5a58a63bc926f4675dc53b">52</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga425f36ab6d5a58a63bc926f4675dc53b">micro_os_plus_trace_initialise</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a0d039b1f2025b3ce6178d4394a785728">detail::tracer&lt;detail::implementation&gt;::initialise</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlight">ssize_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">58</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#ga80d104ecf38dfcf40cae10bac0d2c562">micro_os_plus_trace_write</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* buf, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> nbyte)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aa2d6c80ffc49710b88ba91e0c0d6e503">detail::tracer&lt;detail::implementation&gt;::write</a> (buf, nbyte);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#gac34c391936f919c141bc38ec5b5a1db9">64</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-implementation/#gac34c391936f919c141bc38ec5b5a1db9">micro_os_plus_trace_flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#aca35e085ab85a4e69a6ef41178871484">detail::tracer&lt;detail::implementation&gt;::flush</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">72</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga10e8dda4991909bc9b401c4f401f1364">micro_os_plus_trace_printf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlight">  std::va_list arguments;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlight">  va_start (arguments, format);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ret</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlight">      = <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">detail::tracer&lt;detail::implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlight">  va_end (arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> ret;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga61e826d87556c899edad6f82d7bd36ef">85</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga61e826d87556c899edad6f82d7bd36ef">micro_os_plus_trace_vprintf</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, va_list arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4176d29127dbd89ba01a79770808d094">detail::tracer&lt;detail::implementation&gt;::vprintf</a> (format, arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">91</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#ga378825eb60900b367774de9e76925b0d">micro_os_plus_trace_puts</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a2f7941dcb7ddb9f6afd664ad0c1c9979">detail::tracer&lt;detail::implementation&gt;::puts</a> (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00096"></a>96</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00097"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">97</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-main/#gaf651ff851996a49b25989c93118142f9">micro_os_plus_trace_putchar</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#ad0af55a735d06c5c25c8bf38dc3fd4fd">detail::tracer&lt;detail::implementation&gt;::putchar</a> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00103"></a><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra/#ga49bd9637ae06ff570445fbc6830f19a7">103</a></span><span class="doxyLineContent"><span class="doxyHighlight"><a href="/diag-trace-xpack/docs/api/groups/micro-os-plus-diag-trace-c-api-extra/#ga49bd9637ae06ff570445fbc6830f19a7">micro_os_plus_trace_dump_args</a> (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00104"></a>104</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00105"></a>105</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/diag-trace-xpack/docs/api/classes/micro-os-plus/trace/detail/tracer/#a4e2e2a73a7ec36ac69d94840eb0b52e2">detail::tracer&lt;detail::implementation&gt;::dump_args</a> (argc, argv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00107"></a>107</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00108"></a>108</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00109"></a>109</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00110"></a>110</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00111"></a>111</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00112"></a>112</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
