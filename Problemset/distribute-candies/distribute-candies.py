
# @Title: 分糖果 (Distribute Candies)
# @Author: rubychen0611
# @Date: 2021-01-24 13:02:00
# @Runtime: 92 ms
# @Memory: 16.3 MB

class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        n = len(candyType)
        nb_type = len(set(candyType))
        if nb_type > n / 2:
            return int(n / 2)
        else:
            return nb_type
