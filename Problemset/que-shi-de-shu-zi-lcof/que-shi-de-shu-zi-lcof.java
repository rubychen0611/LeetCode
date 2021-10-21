
// @Title: 0～n-1中缺失的数字 (缺失的数字  LCOF)
// @Author: rubychen0611
// @Date: 2021-08-30 00:15:00
// @Runtime: 0 ms
// @Memory: 38.6 MB

class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length + 1;
        int x = 0;
        for(int i = 0; i < n; i++)
            x ^= i;
        for(int num: nums)
            x ^= num;
        return x;
    }
}
