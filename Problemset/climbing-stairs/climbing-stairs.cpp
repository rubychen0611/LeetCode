
// @Title: 爬楼梯 (Climbing Stairs)
// @Author: rubychen0611
// @Date: 2021-01-25 20:30:11
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    int climbStairs(int n) {
        // f(n) = f(n-1) + f(n-2)
        if (n == 1 || n == 2)
            return n;
        int f1 = 2, f2 = 1, tmp;
        for (int i = 3; i <= n; i++)
        {
            tmp = f1 + f2;
            f2 = f1;
            f1 = tmp;
        }
        return tmp;

    }
};

