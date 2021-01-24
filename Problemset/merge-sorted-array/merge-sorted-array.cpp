
// @Title: 合并两个有序数组 (Merge Sorted Array)
// @Author: rubychen0611
// @Date: 2021-01-04 14:46:59
// @Runtime: 4 ms
// @Memory: 9.3 MB

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1;
        for(int i = m+n-1; i >= 0; i--)
        {
            if (p >= 0 && q >= 0) {
                if (nums1[p] >= nums2[q]) {
                    nums1[i] = nums1[p];
                    p--;
                } else {
                    nums1[i] = nums2[q];
                    q--;
                }
            }
            else if (q >= 0)
            {
                nums1[i] = nums2[q];
                q--;
            }
        }
    }
};

