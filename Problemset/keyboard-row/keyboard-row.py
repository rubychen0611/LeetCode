
# @Title: 键盘行 (Keyboard Row)
# @Author: rubychen0611
# @Date: 2021-01-24 12:56:22
# @Runtime: 32 ms
# @Memory: 14.9 MB

class Solution:
    def find_which_line(self, L, ch):
        for i in range(3):
            if ch in L[i]:
                return i;
        return -1

    def findWords(self, words: List[str]) -> List[str]:
        L = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        ans = []
        for word in words:
            lower_word = word.lower()
            line = self.find_which_line(L, lower_word[0])
            flag = True
            for i in range(1, len(lower_word)):
                if self.find_which_line(L, lower_word[i]) != line:
                    flag = False
                    break
            if flag:
                ans.append(word)
        return ans


            
