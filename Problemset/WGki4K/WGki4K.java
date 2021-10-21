
// @Title: 只出现一次的数字  (只出现一次的数字 )
// @Author: rubychen0611
// @Date: 2021-08-29 21:13:07
// @Runtime: 2 ms
// @Memory: 38 MB

class Solution {
    public int singleNumber(int[] nums) {
        int[] bitSums = new int[32];
        for(int num: nums)
        {
            for(int i = 0; i < 32; i++)
            {
                bitSums[i] += (num >> (31 - i)) & 1;
            }
        }
        int result = 0;
        for(int i = 0; i < 32; i++)
        {
            bitSums[i] %= 3;
            result = (result << 1) + bitSums[i];
        }
        return result;
    }
}
