
# @Title: 单词规律 (Word Pattern)
# @Author: rubychen0611
# @Date: 2021-01-23 15:15:11
# @Runtime: 36 ms
# @Memory: 14.9 MB

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map1 = {}
        map2 = {}
        strs = s.split()
        if len(pattern) != len(strs):
            return False
        for ch, word in zip(pattern, strs):
            if ch not in map1.keys() and word not in map2.keys():
                map1[ch] = word
                map2[word] = ch
            elif ch not in map1.keys() or word not in map2.keys():
                return False
            elif map1[ch] != word or map2[word] != ch:
                return False
        return True
