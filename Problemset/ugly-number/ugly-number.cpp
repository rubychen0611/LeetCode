
// @Title: 丑数 (Ugly Number)
// @Author: rubychen0611
// @Date: 2021-01-22 20:59:40
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {

public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;
        return num == 1;
    }
};

