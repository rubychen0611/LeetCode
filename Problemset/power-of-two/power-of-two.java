
// @Title: 2的幂 (Power of Two)
// @Author: rubychen0611
// @Date: 2021-08-29 23:14:03
// @Runtime: 1 ms
// @Memory: 35.2 MB

class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
}
