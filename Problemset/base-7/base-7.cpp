
// @Title: 七进制数 (Base 7)
// @Author: rubychen0611
// @Date: 2021-02-13 19:33:25
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool sign = false;
        if(num < 0)
        {
            sign = true;
            num = -num;
        }
        string ans;
        while(num)
        {
            int a = num / 7, b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        if(sign)
            ans = "-" + ans;
        return ans;
    }
};

