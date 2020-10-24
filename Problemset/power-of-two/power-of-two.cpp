
// @Title: 2的幂 (Power of Two)
// @Author: rubychen0611
// @Date: 2018-07-06 15:26:38
// @Runtime: 20 ms
// @Memory: N/A

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n == 0)
            return false;
        while(n % 2 == 0)
            n >>= 1;
        if(n == 1)
            return true;
        else return false;
    }
};
