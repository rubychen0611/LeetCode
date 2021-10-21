
// @Title: 阶乘后的零 (Factorial Trailing Zeroes)
// @Author: rubychen0611
// @Date: 2021-03-01 10:16:59
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0)
        {
            count += (n / 5);
            n /= 5;
        }
        return count;
    }
};
