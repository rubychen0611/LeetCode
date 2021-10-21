
// @Title: 回文子字符串的个数 (回文子字符串的个数)
// @Author: rubychen0611
// @Date: 2021-10-08 09:30:49
// @Runtime: 16 ms
// @Memory: 7.5 MB

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        int count = 0;
        for(int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
            count ++;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j + i < n; j++) {
                if((i == 1 || isPalindrome[j+1][j+i-1]) && s[j] == s[j+i]) {
                    isPalindrome[j][j + i] = true;
                    count ++;
                }
            }
        }
        return count;
    }
};

