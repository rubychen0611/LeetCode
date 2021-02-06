
// @Title: 搜索旋转排序数组 (Search in Rotated Sorted Array)
// @Author: rubychen0611
// @Date: 2021-01-31 19:02:41
// @Runtime: 4 ms
// @Memory: 10.8 MB

class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int right, int target)
    {
        if (left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[left] <= nums[mid]) //[left,mid] 连续递增 注意一定是<=,否则[3,1] 1 测试用例过不了
        {
            if(nums[left] <= target && target < nums[mid])
                return binarySearch(nums, left, mid - 1, target);
            else
                return binarySearch(nums, mid + 1, right, target);

        }
        else //[mid,right] 连续递增
        {
            if (nums[mid] < target && target <= nums[right])
                return binarySearch(nums, mid + 1, right, target);
            else return binarySearch(nums, left, mid - 1, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

