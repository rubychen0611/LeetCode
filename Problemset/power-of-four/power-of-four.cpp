
// @Title: 4的幂 (Power of Four)
// @Author: rubychen0611
// @Date: 2021-08-29 23:23:09
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};
