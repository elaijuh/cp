# Minimum Size Subarray Sum
**LeetCode:** [Problem 209](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

**Difficulty:** medium

**Topics:** [#array](https://leetcode.com/tag/array),[#binary-search](https://leetcode.com/tag/binary-search),[#sliding-window](https://leetcode.com/tag/sliding-window),[#prefix-sum](https://leetcode.com/tag/prefix-sum)

## Problem Description

Given an array of positive integers <code>nums</code> and a positive integer <code>target</code>, return <em>the <strong>minimal length</strong> of a </em><span data-keyword="subarray-nonempty"><em>subarray</em></span><em> whose sum is greater than or equal to</em> <code>target</code>. If there is no such subarray, return <code>0</code> instead.</p>

<p>&nbsp;</p>


## Examples

### Example 1:
<pre><strong>Input:</strong> target = 7, nums = [2,3,1,2,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The subarray [4,3] has the minimal length under the problem constraint.</pre>

### Example 2:
<pre><strong>Input:</strong> target = 4, nums = [1,4,4]
<strong>Output:</strong> 1</pre>

### Example 3:
<pre><strong>Input:</strong> target = 11, nums = [1,1,1,1,1,1,1,1]
<strong>Output:</strong> 0</pre>

## Constraints

- <code>1 &lt;= target &lt;= 10<sup>9</sup></code>
- <code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code>
- <code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code>


