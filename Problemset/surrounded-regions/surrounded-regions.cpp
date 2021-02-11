
// @Title: 被围绕的区域 (Surrounded Regions)
// @Author: rubychen0611
// @Date: 2021-02-08 14:53:31
// @Runtime: 8 ms
// @Memory: 9.8 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    int m, n;
    void expand(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = 'S';
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0], y = j + dir[d][1];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
                expand(board, x, y);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                expand(board, i, 0);
            if(board[i][n-1] == 'O')
                expand(board, i, n-1);
        }
        for(int j = 0; j < n; j ++)
        {
            if(board[0][j] == 'O')
                expand(board, 0, j);
            if(board[m-1][j] == 'O')
                expand(board, m-1, j);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }

    }
};

