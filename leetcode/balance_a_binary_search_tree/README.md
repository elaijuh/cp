# Balance a Binary Search Tree
**LeetCode:** [Problem 1382](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

**Difficulty:** medium

**Topics:** [#divide-and-conquer](https://leetcode.com/tag/divide-and-conquer),[#greedy](https://leetcode.com/tag/greedy),[#tree](https://leetcode.com/tag/tree),[#depth-first-search](https://leetcode.com/tag/depth-first-search),[#binary-search-tree](https://leetcode.com/tag/binary-search-tree),[#binary-tree](https://leetcode.com/tag/binary-tree)

## Problem Description

Given the <code>root</code> of a binary search tree, return <em>a <strong>balanced</strong> binary search tree with the same node values</em>. If there is more than one answer, return <strong>any of them</strong>.</p>

<p>A binary search tree is <strong>balanced</strong> if the depth of the two subtrees of every node never differs by more than <code>1</code>.</p>

<p>&nbsp;</p>


## Examples

### Example 1:
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg" style="width: 500px; height: 319px;" />

<pre><strong>Input:</strong> root = [1,null,2,null,3,null,4,null,null]
<strong>Output:</strong> [2,1,3,null,null,null,4]
<b>Explanation:</b> This is not the only correct answer, [3,1,4,null,2] is also correct.</pre>

### Example 2:
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg" style="width: 224px; height: 145px;" />

<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,1,3]</pre>

## Constraints

- The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.
- <code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code>


