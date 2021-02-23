
// @Title: 岛屿的最大面积 (Max Area of Island)
// @Author: rubychen0611
// @Date: 2021-02-18 12:00:28
// @Runtime: 16 ms
// @Memory: 21.7 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int area = 1;
        grid[i][j] = 2;
        for(int k = 0; k < 4; k++)
        {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y]== 1)
                area += dfs(grid, x, y);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int max = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j);
                    if(max < area)
                        max = area;
                }
            }
        }
        return max;
    }
};
