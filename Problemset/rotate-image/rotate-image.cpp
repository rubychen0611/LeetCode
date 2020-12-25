
// @Title: 旋转图像 (Rotate Image)
// @Author: rubychen0611
// @Date: 2020-12-22 16:36:21
// @Runtime: 4 ms
// @Memory: 7.2 MB

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i < (n+1) / 2; i++) {
            for (int j = 0; j < (n+2) / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = temp;


//                for(int p = 0; p <= n; p++)
//                {
//                    for(int q = 0; q <= n; q++)
//                    {
//                        cout << matrix[p][q] << " ";
//                    }
//                    cout << endl;
//               }
            }

        }
        return;
    }
};

