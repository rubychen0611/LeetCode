
// @Title: 二进制中1的个数 (二进制中1的个数 LCOF)
// @Author: rubychen0611
// @Date: 2021-08-29 23:09:58
// @Runtime: 1 ms
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
