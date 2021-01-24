
// @Title: 岛屿的周长 (Island Perimeter)
// @Author: rubychen0611
// @Date: 2021-01-23 13:39:22
// @Runtime: 120 ms
// @Memory: 93.7 MB

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int border = 0, land = 0;
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    land ++;
                    if (j + 1 < n && grid[i][j+1] == 1)
                        border ++;
                    if (i + 1 < m && grid[i+1][j] == 1)
                        border ++;
                }
                
            }
        }
        return 4 * land - 2 * border;
    }
};
