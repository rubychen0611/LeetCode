
// @Title: 合并排序的数组 (Sorted Merge LCCI)
// @Author: rubychen0611
// @Date: 2020-12-20 14:07:06
// @Runtime: 0 ms
// @Memory: 9.3 MB

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> A1(A.begin(), A.begin()+ m);
        int i = 0, j = 0;
        for(int k = 0; k < m+n; k++) {
            if (i < m && j < n) {
                if (A1[i] <= B[j])
                    A[k] = A1[i++];
                else
                    A[k] = B[j++];
            } else if (i == m)
                A[k] = B[j++];
            else
                A[k] = A1[i++];
        }
    }
};

