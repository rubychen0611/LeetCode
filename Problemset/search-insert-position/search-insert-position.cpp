
// @Title: 搜索插入位置 (Search Insert Position)
// @Author: rubychen0611
// @Date: 2021-02-18 14:09:47
// @Runtime: 4 ms
// @Memory: 9.4 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
