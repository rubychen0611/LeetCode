
// @Title: 机器人的运动范围 (机器人的运动范围  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 15:43:54
// @Runtime: 4 ms
// @Memory: 6.9 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    int k, m, n;
    int sum(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int dfs(vector<vector<int>> & grid, int i, int j)
    {
        int count = 1;
        grid[i][j] = 1;
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0], y = j + dir[d][1];
            if(x >= 0 && y >= 0 && x < m &&y < n && grid[x][y] == 0)
            {
                if(sum(x) + sum(y) <= k)
                    count += dfs(grid, x, y);
                else grid[x][y] = 2;
            }
        }
        return count;
    }
public:
    int movingCount(int m, int n, int k) {
        this -> k = k;
        this -> m = m;
        this -> n = n;
        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
        return dfs(grid, 0, 0);
    }
};
