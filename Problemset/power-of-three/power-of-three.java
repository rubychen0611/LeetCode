
// @Title: 3的幂 (Power of Three)
// @Author: rubychen0611
// @Date: 2021-08-29 23:36:05
// @Runtime: 15 ms
// @Memory: 38.3 MB

class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while(n > 1)
        {
            if (n % 3 == 0)
                n /= 3;
            else 
                return false;
        }
        return true;
    }
}
