
// @Title: 汉明距离 (Hamming Distance)
// @Author: rubychen0611
// @Date: 2021-02-13 19:56:20
// @Runtime: 0 ms
// @Memory: 5.9 MB

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while(z)
        {
            count += (z % 2);
            z /= 2;
        }
        return count;
    }
};
