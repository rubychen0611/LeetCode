
// @Title: 搜索插入位置 (Search Insert Position)
// @Author: rubychen0611
// @Date: 2021-01-31 23:03:33
// @Runtime: 4 ms
// @Memory: 9.5 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

