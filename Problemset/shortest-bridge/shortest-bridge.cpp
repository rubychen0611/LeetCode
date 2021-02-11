
// @Title: 最短的桥 (Shortest Bridge)
// @Author: rubychen0611
// @Date: 2021-02-07 14:08:36
// @Runtime: 44 ms
// @Memory: 19.6 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
private:
    int n;
    queue<pair<int, int>>points;
    void dfsMark(vector<vector<int>>& A, int i, int j)
    {
        points.push(pair<int,int>{i, j});
        A[i][j] = 2;
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0], y = j + dir[d][1];
            if(x >= 0 && x < n && y >= 0 && y < n && A[x][y] == 1)
                dfsMark(A, x, y);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (A[i][j] == 1)
                {
                    dfsMark(A, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        int level = 0;
        while(!points.empty())
        {
            int n_points = points.size();
            for(int i = 0 ; i < n_points; i++)
            {
                pair<int, int> p = points.front();
                for (int d = 0; d < 4; d++)
                {
                    int x = p.first + dir[d][0], y = p.second + dir[d][1];
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        if (A[x][y] == 0)
                        {
                            A[x][y] = 2;
                            points.push({x,y});
                        }
                        else if (A[x][y] == 1)
                            return level;

                    }
                }
                points.pop();
            }
            level ++;
        }
        return 0;
    }

};

