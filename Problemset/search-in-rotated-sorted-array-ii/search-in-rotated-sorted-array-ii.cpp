
// @Title: 搜索旋转排序数组 II (Search in Rotated Sorted Array II)
// @Author: rubychen0611
// @Date: 2021-01-31 20:29:29
// @Runtime: 8 ms
// @Memory: 13.5 MB

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] == nums[mid])
            {
                left ++;
            }
            else if (nums[left] < nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }

        }
        return false;
    }
};

