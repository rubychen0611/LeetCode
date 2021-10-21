
// @Title: 左右两边子数组的和相等 (左右两边子数组的和相等)
// @Author: rubychen0611
// @Date: 2021-10-01 20:03:17
// @Runtime: 1 ms
// @Memory: 39 MB

class Solution {
    public int pivotIndex(int[] nums) {
        int totalSum = 0, sum = 0;
        for(int num: nums) {
            totalSum += num;
        }
        for(int i = 0; i < nums.length; i++) {
            if (sum == totalSum - sum - nums[i]) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
}

