
// @Title: 加一 (Plus One)
// @Author: rubychen0611
// @Date: 2021-02-11 11:47:57
// @Runtime: 4 ms
// @Memory: 8.4 MB

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = digits.size() - 1;
        int sum, c = 1, s;

        while(p >= 0)
        {
            sum = digits[p] + c;
            c = sum / 10;
            s = sum % 10;
            digits[p] = s;
            if(c == 0)  
                break;
            p--;
        }
        if(c == 1)
        {
            p = 0;
            digits.push_back(0);
            for(int i = digits.size() - 1; i > 0 ; i--)
            {
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }
        return digits;
    }
};
