
// @Title: 种花问题 (Can Place Flowers)
// @Author: rubychen0611
// @Date: 2021-01-24 20:13:42
// @Runtime: 12 ms
// @Memory: 19.8 MB

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        int size = flowerbed.size();
        int count = 0;
        for(int i = 0; i < size; )
        {
           if (flowerbed[i] == 1)
               i += 2;
           else if (i == size - 1 || flowerbed[i+1] == 0)
           {
               count ++;
               if(count == n)
                   return true;
               i += 2;
           }
           else i += 3;
        }
        return false;
    }
};

