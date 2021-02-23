
// @Title: 在排序数组中查找元素的第一个和最后一个位置 (Find First and Last Position of Element in Sorted Array)
// @Author: rubychen0611
// @Date: 2021-02-18 14:32:51
// @Runtime: 12 ms
// @Memory: 13.4 MB

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int>{-1, -1};
        int left = 0, right = nums.size() - 1;
        int start, end;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        start = left;
        if(start >= nums.size() || start < 0 || nums[start] != target)
            return vector<int>{-1, -1};
        
        left = 0; 
        right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        end = right;
        return vector<int>{start, end};
    }
};
