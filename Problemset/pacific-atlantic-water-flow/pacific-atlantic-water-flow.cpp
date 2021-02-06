
// @Title: 太平洋大西洋水流问题 (Pacific Atlantic Water Flow)
// @Author: rubychen0611
// @Date: 2021-02-06 19:14:53
// @Runtime: 32 ms
// @Memory: 14.8 MB


int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {

private:
    int m, n;
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& reach, int i, int j)
    {
        reach[i][j] = true;
        int x, y;
        for(int d = 0; d < 4; d++)
        {
            x = i + direction[d][0];
            y = j + direction[d][1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] >= matrix[i][j]) // 坐标合法
            {
                if (!reach[x][y])
                    dfs(matrix, reach, x, y);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.empty() || matrix[0].empty())
            return ans;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> reach_pacific(m, vector<bool>(n, false));
        vector<vector<bool>> reach_atlantic(m, vector<bool>(n, false));
        int i, j;
        for(i = 0; i < m; i++)
        {
            dfs(matrix, reach_pacific, i, 0);
            dfs(matrix, reach_atlantic, i, n-1);
        }
        for(j = 0; j < n; j++)
        {
            dfs(matrix, reach_pacific, 0, j);
            dfs(matrix, reach_atlantic, m-1, j);
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j ++)
            {
                if(reach_pacific[i][j] && reach_atlantic[i][j])
                    ans.push_back(vector<int>{i,j});
            }
        }
        return ans;
    }
};

