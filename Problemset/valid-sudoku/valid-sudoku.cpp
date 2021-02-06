
// @Title: 有效的数独 (Valid Sudoku)
// @Author: rubychen0611
// @Date: 2021-01-24 17:08:21
// @Runtime: 28 ms
// @Memory: 17.3 MB

class Solution {
private:
    bool isValid9(char chars[9])
    {
        bool flag[9] = {false};
        for (int i = 0; i < 9; i++)
        {
            char ch = chars[i];
            if (ch == '.')
                continue;
            if (flag[ch - '1'] == true)
                return false;
            else
                flag[ch - '1'] = true;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char chars[9];
        int i, j, k, l;
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                chars[j] = board[i][j];
            }
            if (!isValid9(chars))
                return false;
        }
        for (j = 0; j < 9; j++)
        {
            for (i = 0; i < 9; i++)
            {
                chars[i] = board[i][j];
            }
            if (!isValid9(chars))
                return false;
        }
        int count = 0;
        for(i = 0; i < 9; i += 3)
        {
            for(j = 0; j < 9; j += 3)
            {
                count = 0;
                for(k = i; k < i+3; k++)
                {
                    for (l = j; l < j + 3; l++)
                    {
                        chars[count++] = board[k][l];
                    }
                }
                if (!isValid9(chars))
                    return false;
            }
        }
        return true;
            
    }
};
