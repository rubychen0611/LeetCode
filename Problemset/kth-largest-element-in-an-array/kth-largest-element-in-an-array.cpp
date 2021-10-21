
// @Title: 数组中的第K个最大元素 (Kth Largest Element in an Array)
// @Author: rubychen0611
// @Date: 2021-10-18 10:19:18
// @Runtime: 116 ms
// @Memory: 9.6 MB

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
    int Select(vector<int>& a, int left, int right, int findIdx)
    {
        if (left == right)
            return a[left];
        int x = Partition(a, left, right);
        if (x == findIdx)
            return a[x];
        else if (x > findIdx)
            return Select(a, left, x - 1, findIdx);
        else
            return Select(a, x + 1, right, findIdx);
    }
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return Select(nums, 0, nums.size()-1, k - 1);
    }
};

