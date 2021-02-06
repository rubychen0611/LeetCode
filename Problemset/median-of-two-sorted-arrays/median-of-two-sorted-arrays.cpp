
// @Title: 寻找两个正序数组的中位数 (Median of Two Sorted Arrays)
// @Author: rubychen0611
// @Date: 2021-02-01 14:38:30
// @Runtime: 60 ms
// @Memory: 86.7 MB

class Solution {
private:
    int min (int a, int b)
    {
        return a < b ? a : b;
    }
    int getKth(vector<int> &nums1,  vector<int> &nums2, int k)
    {
        int l1 = nums1.size(), l2 = nums2.size();
        int start1 = 0, start2 = 0;
        while(true)
        {
            if (start1 == l1)
                return nums2[start2 + k - 1];
            if (start2 == l2)
                return nums1[start1 + k - 1];
            if (k == 1)
                return min(nums1[start1], nums2[start2]);
            int new_start1 = min(start1 + k / 2 - 1, l1 - 1);
            int new_start2 = min(start2 + k / 2 - 1, l2 - 1);
            int pivot1 = nums1[new_start1], pivot2 = nums2[new_start2];
            if (pivot1 <= pivot2)
            {
                k -=(new_start1 - start1 + 1);
                start1 = new_start1 + 1;
            }
            else
            {
                k -=(new_start2 - start2 + 1);
                start2 = new_start2 + 1;
            }

        }

    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1)
            return getKth(nums1, nums2, (len + 1) / 2);
        else {
            int left = getKth(nums1, nums2, len / 2 + 1);
            int right = getKth(nums1, nums2, len / 2);
            return (left + right) / 2.0;
        }
    }
};

