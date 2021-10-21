
// @Title: 字符串相加 (Add Strings)
// @Author: rubychen0611
// @Date: 2021-03-01 10:29:38
// @Runtime: 24 ms
// @Memory: 54.8 MB

class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.length() - 1, p2 = num2.length() - 1;
        string ans = "";
        int c = 0; // 进位
        int sum, t;
        while(p1 >= 0 || p2 >= 0)
        {
            sum = c;
            if(p1 >= 0)
            {
                sum += (num1[p1] - '0');
                p1 --;
            }
            if(p2 >= 0)
            {
                sum += (num2[p2] - '0');
                p2 --;
            }
            t = sum % 10;
            c = sum / 10;
            ans = (char)(t + '0') + ans;
        }
        
        if (c > 0)
        {
            ans = (char)(c + '0') + ans;
        }
        return ans;
    }
};
