
// @Title: 长度最小的子数组 (Minimum Size Subarray Sum)
// @Author: rubychen0611
// @Date: 2021-09-03 16:07:49
// @Runtime: 1 ms
// @Memory: 38.4 MB

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, right = 0, min = Integer.MAX_VALUE;
        int sum = 0;
        for(right = 0; right < nums.length; right ++)
        {
            sum += nums[right];
            while(left <= right && sum >= target)
            {
                if(min > right - left + 1)
                    min = right - left + 1;
                sum -= nums[left++];
            }
        }
        if (min == Integer.MAX_VALUE)
            min = 0;
        return min;
    }
}
