
// @Title: 搜索二维矩阵 II (Search a 2D Matrix II)
// @Author: rubychen0611
// @Date: 2020-12-22 16:51:52
// @Runtime: 192 ms
// @Memory: 15 MB

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(j >= 0 && i < m)
        {
            if (matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else i++;
        }
        return false;
    }
};

