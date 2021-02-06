
// @Title: 一和零 (Ones and Zeroes)
// @Author: rubychen0611
// @Date: 2021-02-02 15:18:25
// @Runtime: 456 ms
// @Memory: 9.5 MB

struct BinaryString
{
    int num0, num1;
    BinaryString(){}
    BinaryString(string str){
        num0 = 0;
        num1 = 0;
        for(const char & ch: str)
        {
            if (ch == '0')
                num0 ++;
            else
                num1 ++;
        }
    }
};
class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int size = strs.size();
        vector<BinaryString> bstrs(size);
        for (int i = 0; i < size; i++)
            bstrs[i] = BinaryString(strs[i]);
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for (int k = 0; k < size; k++)
        {
            for (int i = m; i >= bstrs[k].num0; i--)
            {
                for (int j = n; j >= bstrs[k].num1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - bstrs[k].num0][j - bstrs[k].num1] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

