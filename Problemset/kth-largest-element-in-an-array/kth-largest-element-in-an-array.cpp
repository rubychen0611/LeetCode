
// @Title: 数组中的第K个最大元素 (Kth Largest Element in an Array)
// @Author: rubychen0611
// @Date: 2020-12-20 13:11:31
// @Runtime: 256 ms
// @Memory: 10.3 MB

class Solution {
private:
    int Partition(vector<int>& a, int left, int right)
    {
        int x = a[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++)
        {
            if (a[j] >= x)
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i+1], a[right]);
        return i + 1;
    }
    int Select(vector<int>& a, int left, int right, int i)
    {
        if (left == right)
            return a[left];
        int x = Partition(a, left, right);
        int k = x - left + 1;   // 当前的x是第几个数字
        if (i == k)
            return a[x];
        else if (i < k)
            return Select(a, left, x - 1, i);
        else
            return Select(a, x + 1, right, i - k);
    }
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return Select(nums, 0, nums.size()-1, k);
    }
};

