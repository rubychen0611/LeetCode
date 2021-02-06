
// @Title: 寻找旋转排序数组中的最小值 (Find Minimum in Rotated Sorted Array)
// @Author: rubychen0611
// @Date: 2021-01-31 21:12:37
// @Runtime: 4 ms
// @Memory: 9.8 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            if (nums[left] <= nums[right])
                return nums[left];
            mid = left + (right - left) / 2;
           if (nums[left] <= nums[mid])
                left = mid +1;
            else
                right = mid;
        }
        return nums[right];
    }
};

