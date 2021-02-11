
// @Title: 单词搜索 (Word Search)
// @Author: rubychen0611
// @Date: 2021-02-07 11:22:05
// @Runtime: 64 ms
// @Memory: 19.1 MB

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    int m, n;

    bool backtrace(vector<vector<char>>& board, string word, int i, int j, int pos)
    {
        //cout << i << " " << j <<endl;
        if(pos == word.length() - 1)
            return true;
        char tmp = board[i][j];
        board[i][j] = ' ';
        for(int d = 0; d < 4; d++)
        {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] != ' ' && board[x][y] == word[pos+1])
            {
                if(backtrace(board, word, x, y, pos + 1))
                {
                    board[i][j] = tmp;
                    return true;
                }
            }
        }
        board[i][j] = tmp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty() || board.empty() || board[0].empty())
            return false;
        char start = word[0];
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (start == board[i][j])
                {
                    if (backtrace(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

