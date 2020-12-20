
// @Title: 最大子序和 (Maximum Subarray)
// @Author: rubychen0611
// @Date: 2020-12-20 16:23:56
// @Runtime: 16 ms
// @Memory: 13.3 MB

class Solution {
private:
    int MAX_INT = 0xFFFFFFF;
    int max(int a, int b, int c)
    {
        if (a >= b && a >= c)
            return a;
        else if (b >= a && b >= c)
            return b;
        else return c;
    }
    int findCrossingMaxSumArray(vector<int>&a, int left, int mid, int right)
    {
        int left_max = -MAX_INT, right_max = -MAX_INT, left_sum = 0, right_sum = 0;
        for (int i = mid; i >= left; i--)
        {
            left_sum += a[i];
            if (left_sum > left_max)
                left_max = left_sum;
        }
        for (int i = mid+1; i <= right; i++)
        {
            right_sum += a[i];
            if (right_sum > right_max)
                right_max = right_sum;
        }
        return left_max + right_max;
    }
    int findMaxSubArray(vector<int>& a, int left, int right)
    {
        if(left == right)
            return a[left];
        int mid = (left + right) / 2;
        int left_max = findMaxSubArray(a, left, mid);
        int right_max = findMaxSubArray(a, mid+1, right);
        int crossing_max = findCrossingMaxSumArray(a, left, mid, right);
        return max(left_max, right_max, crossing_max);
    }
public:
    int maxSubArray(vector<int>& nums) {
        return findMaxSubArray(nums, 0, nums.size()-1);
    }
};

