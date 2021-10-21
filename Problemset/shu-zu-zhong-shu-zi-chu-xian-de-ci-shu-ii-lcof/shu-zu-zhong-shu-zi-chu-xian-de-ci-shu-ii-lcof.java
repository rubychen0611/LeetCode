
// @Title: 数组中数字出现的次数 II (数组中数字出现的次数 II LCOF)
// @Author: rubychen0611
// @Date: 2021-08-29 23:44:33
// @Runtime: 4 ms
// @Memory: 39.3 MB

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
