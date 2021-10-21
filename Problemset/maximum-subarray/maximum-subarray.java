
// @Title: 最大子序和 (Maximum Subarray)
// @Author: rubychen0611
// @Date: 2021-07-11 22:02:29
// @Runtime: 1 ms
// @Memory: 38.2 MB

class Solution {
    private final int MAX_INT = 0xFFFFFFF;
    private int findCrossingMaxSubArray(int[] nums, int left, int right, int mid)
    {
        int left_max = 0, right_max = 0, left_sum = 0, right_sum = 0;
        for(int i = mid - 1; i >= left; i--)
        {
            left_sum += nums[i];
            if (left_sum > left_max)
                left_max = left_sum;
        }
        for (int i = mid + 1; i <= right; i++)
        {
            right_sum += nums[i];
            if (right_sum > right_max)
                right_max = right_sum;
        }
        return left_max + right_max + nums[mid];
    }

    private int recursiveFindMaxSubArray(int[] nums, int left, int right)
    {
        if (left >= right)
            return nums[left];
        int mid = (left + right) / 2;
        int left_max = recursiveFindMaxSubArray(nums, left, mid-1);
        int right_max = recursiveFindMaxSubArray(nums, mid + 1, right);
        int crossing_max = findCrossingMaxSubArray(nums, left, right, mid);
        return Math.max(Math.max(left_max, right_max), crossing_max);
    }
    public int maxSubArray(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        return recursiveFindMaxSubArray(nums, 0, nums.length - 1);
    }
}
