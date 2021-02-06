
// @Title: 有序数组中的单一元素 (Single Element in a Sorted Array)
// @Author: rubychen0611
// @Date: 2021-02-01 11:26:24
// @Runtime: 4 ms
// @Memory: 10.8 MB

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(mid % 2 == 1)
            {
                if (nums[mid - 1] == nums[mid])
                    left = mid + 1;
                else if (nums[mid + 1] == nums[mid])
                    right = mid - 1;
            }
            else if (mid % 2 == 0)
            {
                if (mid + 1 < nums.size() && nums[mid + 1] == nums[mid])
                    left = mid + 1;
                else if (mid - 1 > 0 && nums[mid - 1] == nums[mid])
                    right = mid - 1;
                else
                    return nums[mid];
            }
        }
        return -1;
    }
};

