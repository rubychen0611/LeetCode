
// @Title: 岛屿数量 (Number of Islands)
// @Author: rubychen0611
// @Date: 2021-02-08 21:34:56
// @Runtime: 16 ms
// @Memory: 9.2 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0], y = j + dir[d][1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

