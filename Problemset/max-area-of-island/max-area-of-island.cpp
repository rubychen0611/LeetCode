
// @Title: 岛屿的最大面积 (Max Area of Island)
// @Author: rubychen0611
// @Date: 2021-02-06 13:26:17
// @Runtime: 20 ms
// @Memory: 21.9 MB

//enum State{UNEXPLORED, EXPLORING, EXPLORED};
class Solution {
private:
    int calculateArea(vector<vector<int>>& grid, int i, int j)
    {
        //state[i][j] = EXPLORING;
        grid[i][j] = 0;
        int left = 0, right = 0, up = 0, down = 0;
        if (i - 1 >= 0 && grid[i-1][j] == 1)
            left = calculateArea(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i+1][j] == 1)
            right = calculateArea(grid,i + 1, j);
        if (j - 1 >= 0 && grid[i][j-1] == 1)
            up = calculateArea(grid, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j+1] == 1 )
            down = calculateArea(grid, i, j + 1);
        //state[i][j] = EXPLORED;

        return 1 + left + right + up + down;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int max = 0;
        int m = grid.size(), n = grid[0].size(), area;
        //vector<vector<State>> state(m, vector<State>(n, UNEXPLORED));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    area = calculateArea(grid, i, j);
                    if(area > max)
                        max = area;
                }
            }
        }
        return max;
    }
};

