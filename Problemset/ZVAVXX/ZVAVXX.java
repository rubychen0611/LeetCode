
// @Title: 乘积小于 K 的子数组 (乘积小于 K 的子数组)
// @Author: rubychen0611
// @Date: 2021-09-05 23:01:04
// @Runtime: 5 ms
// @Memory: 45.2 MB

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int left = 0, right = 0;
        int product = 1;
        int ans = 0;
        for(right = 0; right < nums.length; right ++)
        {
            product *= nums[right];
            while(left <= right && product >= k)
            {
                product /= nums[left];
                left ++;
            }
            ans += right >= left ? right - left + 1: 0;
        }
        return ans;
    }
}
