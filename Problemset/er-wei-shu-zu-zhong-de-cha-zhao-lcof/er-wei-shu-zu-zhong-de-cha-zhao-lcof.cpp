
// @Title: 二维数组中的查找 (二维数组中的查找 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-13 01:00:39
// @Runtime: 20 ms
// @Memory: 12.7 MB

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i >= 0 && j >= 0 && i < m && j < n)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                j--;
            else i++;
        }
        return false;
    }
};
