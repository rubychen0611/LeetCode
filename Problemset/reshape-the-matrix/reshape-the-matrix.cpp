
// @Title: 重塑矩阵 (Reshape the Matrix)
// @Author: rubychen0611
// @Date: 2021-01-22 16:27:15
// @Runtime: 20 ms
// @Memory: 10.4 MB

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.empty())
            return nums;
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c)
            return nums;
        vector<vector<int>> new_mat(r,vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int idx = i * c + j;
                new_mat[i][j] = nums[idx / n][idx % n];
            }
        }
        return new_mat;
    }
};

