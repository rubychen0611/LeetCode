
// @Title: 查找插入位置 (查找插入位置)
// @Author: rubychen0611
// @Date: 2021-10-12 20:56:24
// @Runtime: 4 ms
// @Memory: 9.2 MB

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
