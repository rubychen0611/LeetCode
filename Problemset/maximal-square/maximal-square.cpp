
// @Title: 最大正方形 (Maximal Square)
// @Author: rubychen0611
// @Date: 2021-01-26 13:51:24
// @Runtime: 20 ms
// @Memory: 11.3 MB

class Solution {
private:
    int min (int a, int b)
    {
        return a < b ? a : b;
    }
    int min (int a, int b, int c)
    {
        return min(min(a,b), c);
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        int max = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                if (i == 0 || j == 0)
                    f[i][j] = 1;
                else
                    f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1;
                if (f[i][j] > max)
                    max = f[i][j];
            }
        }
        return max * max;
    }
};

