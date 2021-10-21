
// @Title: 4的幂 (Power of Four)
// @Author: rubychen0611
// @Date: 2021-08-29 23:26:05
// @Runtime: 1 ms
// @Memory: 35.6 MB

class Solution {
    public boolean isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && (n & 0x55555555) > 0;
    }
}
