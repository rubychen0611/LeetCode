
| [English](README_EN.md) | 简体中文 |

# [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

## 题目描述

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code> ，写一个函数来判断 <code>s2</code> 是否包含 <code>s1</code><strong>&nbsp;</strong>的排列。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>换句话说，<code>s1</code> 的排列之一是 <code>s2</code> 的 <strong>子串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出：</strong>true
<strong>解释：</strong>s2 包含 s1 的排列之一 ("ba").
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1= "ab" s2 = "eidboaoo"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅包含小写字母</li>
</ul>


## 相关话题

- [哈希表](https://leetcode-cn.com/tag/hash-table)
- [双指针](https://leetcode-cn.com/tag/two-pointers)
- [字符串](https://leetcode-cn.com/tag/string)
- [滑动窗口](https://leetcode-cn.com/tag/sliding-window)

## 相似题目

- [最小覆盖子串](../minimum-window-substring/README.md)
- [找到字符串中所有字母异位词](../find-all-anagrams-in-a-string/README.md)
