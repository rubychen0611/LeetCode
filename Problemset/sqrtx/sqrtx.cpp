
// @Title: x 的平方根 (Sqrt(x))
// @Author: rubychen0611
// @Date: 2021-01-29 00:37:09
// @Runtime: 4 ms
// @Memory: 5.8 MB

class Solution {
private:
    int find(int left, int right, int x)
    {
        if (left > right)
            return right;

        int mid =left + (right - left) / 2;
        int sqrt = x / mid;
        if (mid == sqrt)
            return mid;
        else if (sqrt > mid)
            return find(mid + 1, right, x);
        else return find(left, mid - 1, x);

    }
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        else if (x == 2)
            return 1;
        return find(1, x / 2, x);
    }
};

