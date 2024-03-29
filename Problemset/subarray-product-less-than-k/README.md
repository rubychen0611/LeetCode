
| [English](README_EN.md) | 简体中文 |

# [713. 乘积小于K的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/)

## 题目描述

<p>给定一个正整数数组 <code>nums</code>和整数 <code>k</code> 。</p>

<p>请找出该数组内乘积小于 <code>k</code> 的连续的子数组的个数。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [10,5,2,6], k = 100
<strong>输出:</strong> 8
<strong>解释:</strong> 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3], k = 0
<strong>输出:</strong> 0</pre>

<p> </p>

<p><strong>提示: </strong></p>

<ul>
	<li><code>1 <= nums.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
	<li><code>0 <= k <= 10<sup>6</sup></code></li>
</ul>


## 相关话题

- [数组](https://leetcode-cn.com/tag/array)
- [滑动窗口](https://leetcode-cn.com/tag/sliding-window)

## 相似题目

- [乘积最大子数组](../maximum-product-subarray/README.md)
- [和等于 k 的最长子数组长度](../maximum-size-subarray-sum-equals-k/README.md)
- [和为 K 的子数组](../subarray-sum-equals-k/README.md)
- [小于 K 的两数之和](../two-sum-less-than-k/README.md)
