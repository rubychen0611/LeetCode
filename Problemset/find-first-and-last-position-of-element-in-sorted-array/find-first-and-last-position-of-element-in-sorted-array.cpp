
// @Title: 在排序数组中查找元素的第一个和最后一个位置 (Find First and Last Position of Element in Sorted Array)
// @Author: rubychen0611
// @Date: 2021-01-29 01:19:06
// @Runtime: 4 ms
// @Memory: 13.4 MB

class Solution {
private:
    // 找第一个位置
    int binarySearchStart(vector<int>& nums, int left, int right, int target)
    {
        if (left > right)
            return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            return binarySearchStart(nums, left, mid - 1, target);
        else
            return binarySearchStart(nums, mid + 1, right, target);
    }
    // 找最后一个位置
    int binarySearchEnd(vector<int>& nums, int left, int right, int target)
    {
        if (left > right)
            return right;
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            return binarySearchEnd(nums, mid + 1, right, target);
        else
            return binarySearchEnd(nums, left, mid - 1, target);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        int start = binarySearchStart(nums, 0, nums.size() - 1, target);
        if (start < 0 || start >= nums.size() || nums[start] != target)
            return vector<int>{-1, -1};
        int end = binarySearchEnd(nums, 0, nums.size() - 1, target);
        return vector<int>{start, end};
    }
};

