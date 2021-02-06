
// @Title: 寻找旋转排序数组中的最小值 II (Find Minimum in Rotated Sorted Array II)
// @Author: rubychen0611
// @Date: 2021-01-31 22:54:06
// @Runtime: 8 ms
// @Memory: 11.9 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            if (nums[left] < nums[right] || left == right)  // 注意
                return nums[left];
            mid = left + (right - left) / 2;
            if (nums[left] == nums[mid])
                left ++;
            else if (nums[left] < nums[mid])
                left = mid +1;
            else
                right = mid;
        }
        return -1;
    }
};

