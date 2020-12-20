
// @Title: 排序数组 (Sort an Array)
// @Author: rubychen0611
// @Date: 2020-12-20 13:21:29
// @Runtime: 72 ms
// @Memory: 15.6 MB

class Solution {
private:
    /***************快速排序***************/
    int Partition(vector<int> &a, int left, int right)
    {
        int x = a[right];   // 主元
        int i = left - 1;       // i标记小于x、大于x的分界点
        for (int j = left; j <= right - 1; j++)     // j遍历每个除主元外的元素
        {
            if(a[j] <= x)
            {
                i ++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[right]);
        return i + 1;
    }

    void QuickSort(vector<int> &a, int left, int right)
    {
        if (left < right)
        {
            int pivot = Partition(a, left, right);
            QuickSort(a, left, pivot - 1);
            QuickSort(a, pivot + 1, right);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

