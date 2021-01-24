
# @Title: 猜数字游戏 (Bulls and Cows)
# @Author: rubychen0611
# @Date: 2021-01-24 12:45:37
# @Runtime: 44 ms
# @Memory: 14.7 MB

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a = 0
        b = 0
        hash_map = {}
        for i in range(len(guess)):
            if secret[i] == guess[i]:
                a += 1
            else:
                if secret[i] in hash_map.keys():
                    if hash_map[secret[i]] < 0 :
                        b += 1
                    hash_map[secret[i]] += 1
                else:
                    hash_map[secret[i]] = 1
                if guess[i] in hash_map.keys():
                    if hash_map[guess[i]] > 0:
                        b += 1
                    hash_map[guess[i]] -= 1;
                else:
                    hash_map[guess[i]] = -1
        return "%dA%dB" %(a, b)
