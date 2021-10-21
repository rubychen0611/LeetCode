
// @Title: 位1的个数 (Number of 1 Bits)
// @Author: rubychen0611
// @Date: 2021-08-29 23:08:07
// @Runtime: 0 ms
// @Memory: 35 MB

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        while(n != 0)
        {
            n = n & (n - 1);
            count ++;
        }
        return count;
    }
}
