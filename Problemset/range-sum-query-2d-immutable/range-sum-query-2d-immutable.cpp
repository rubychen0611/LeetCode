
// @Title: 二维区域和检索 - 矩阵不可变 (Range Sum Query 2D - Immutable)
// @Author: rubychen0611
// @Date: 2021-02-12 15:34:16
// @Runtime: 16 ms
// @Memory: 15 MB

class NumMatrix {
private:
    vector<vector<int>> sumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        sumMatrix.resize(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            int row_sum = 0;
            for(int j = 0; j < n; j++)
            {
                row_sum += matrix[i][j];
                sumMatrix[i][j] = row_sum;
                if(i > 0)
                    sumMatrix[i][j] += sumMatrix[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sumMatrix[row2][col2];
        if(row1 > 0)
            sum -= sumMatrix[row1 - 1][col2];
        if(col1 > 0)
            sum -= sumMatrix[row2][col1 - 1];
        if(row1 > 0 && col1 > 0)
            sum += sumMatrix[row1 - 1][col1 - 1];
        return sum;
        //return sumMatrix[row2][col2] - sumMatrix[row1 - 1][col2] - sumMatrix[row2][col1 - 1] + sumMatrix[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
