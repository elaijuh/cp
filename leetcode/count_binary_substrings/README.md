# Count Binary Substrings
**LeetCode:** [Problem 696](https://leetcode.com/problems/count-binary-substrings/description/)

**Difficulty:** easy

**Topics:** [#two-pointers](https://leetcode.com/tag/two-pointers),[#string](https://leetcode.com/tag/string)

## Problem Description

Given a binary string <code>s</code>, return the number of non-empty substrings that have the same number of <code>0</code>&#39;s and <code>1</code>&#39;s, and all the <code>0</code>&#39;s and all the <code>1</code>&#39;s in these substrings are grouped consecutively.</p>

<p>Substrings that occur multiple times are counted the number of times they occur.</p>

<p>&nbsp;</p>


## Examples

### Example 1:
<pre><strong>Input:</strong> s = &quot;00110011&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 substrings that have equal number of consecutive 1&#39;s and 0&#39;s: &quot;0011&quot;, &quot;01&quot;, &quot;1100&quot;, &quot;10&quot;, &quot;0011&quot;, and &quot;01&quot;.
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, &quot;00110011&quot; is not a valid substring because all the 0&#39;s (and 1&#39;s) are not grouped together.</pre>

### Example 2:
<pre><strong>Input:</strong> s = &quot;10101&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 substrings: &quot;10&quot;, &quot;01&quot;, &quot;10&quot;, &quot;01&quot; that have equal number of consecutive 1&#39;s and 0&#39;s.</pre>

## Constraints

- <code>1 &lt;= s.length &lt;= 10<sup>5</sup></code>
- <code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.


