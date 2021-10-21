
// @Title: 3的幂 (Power of Three)
// @Author: rubychen0611
// @Date: 2021-03-01 10:55:06
// @Runtime: 24 ms
// @Memory: 5.9 MB

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};
