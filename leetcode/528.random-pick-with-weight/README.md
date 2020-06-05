# [528. Random Pick with Weight (Medium)](https://leetcode.com/problems/random-pick-with-weight/)

<p>Given an array <code>w</code> of positive integers, where <code>w[i]</code> describes the weight of index <code>i</code>,&nbsp;write a function <code>pickIndex</code>&nbsp;which randomly&nbsp;picks an index&nbsp;in proportion&nbsp;to its weight.</p>

<p>Note:</p>

<ol>
	<li><code>1 &lt;= w.length &lt;= 10000</code></li>
	<li><code>1 &lt;= w[i] &lt;= 10^5</code></li>
	<li><code>pickIndex</code>&nbsp;will be called at most <code>10000</code> times.</li>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">["Solution","pickIndex"]
</span><span id="example-input-1-2">[[[1]],[]]</span>
<strong>Output: </strong><span id="example-output-1">[null,0]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-2-1">["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
</span><span id="example-input-2-2">[[[1,3]],[],[],[],[],[]]</span>
<strong>Output: </strong><span id="example-output-2">[null,0,1,1,1,0]</span></pre>
</div>

<p><strong>Explanation of Input Syntax:</strong></p>

<p>The input is two lists:&nbsp;the subroutines called&nbsp;and their&nbsp;arguments.&nbsp;<code>Solution</code>'s&nbsp;constructor has one argument, the&nbsp;array <code>w</code>. <code>pickIndex</code> has no arguments.&nbsp;Arguments&nbsp;are&nbsp;always wrapped with a list, even if there aren't any.</p>

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Random](https://leetcode.com/tag/random/)

**Similar Questions**:

- [Random Pick Index (Medium)](https://leetcode.com/problems/random-pick-index/)
- [Random Pick with Blacklist (Hard)](https://leetcode.com/problems/random-pick-with-blacklist/)
- [Random Point in Non-overlapping Rectangles (Medium)](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/)
