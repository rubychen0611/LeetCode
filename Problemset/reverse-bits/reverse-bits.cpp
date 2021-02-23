
// @Title: 颠倒二进制位 (Reverse Bits)
// @Author: rubychen0611
// @Date: 2021-02-13 20:07:14
// @Runtime: 4 ms
// @Memory: 5.9 MB

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
