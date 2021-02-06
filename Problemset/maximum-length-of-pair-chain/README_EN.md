
| English | [简体中文](README.md) |

# [646. Maximum Length of Pair Chain](https://leetcode-cn.com/problems/maximum-length-of-pair-chain/)

## Description

<p>
You are given <code>n</code> pairs of numbers. In every pair, the first number is always smaller than the second number.
</p>

<p>
Now, we define a pair <code>(c, d)</code> can follow another pair <code>(a, b)</code> if and only if <code>b < c</code>. Chain of pairs can be formed in this fashion. 
</p>

<p>
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
</p>


<p><b>Example 1:</b><br />
<pre>
<b>Input:</b> [[1,2], [2,3], [3,4]]
<b>Output:</b> 2
<b>Explanation:</b> The longest chain is [1,2] -> [3,4]
</pre>
</p>

<p><b>Note:</b><br>
<ol>
<li>The number of given pairs will be in the range [1, 1000].</li>
</ol>
</p>

## Related Topics

- [Dynamic Programming](https://leetcode-cn.com/tag/dynamic-programming)

## Similar Questions

- [Longest Increasing Subsequence](../longest-increasing-subsequence/README_EN.md)
- [Increasing Subsequences](../increasing-subsequences/README_EN.md)
