
// @Title: x 的平方根 (Sqrt(x))
// @Author: rubychen0611
// @Date: 2021-02-18 13:55:08
// @Runtime: 4 ms
// @Memory: 5.7 MB

class Solution {
public:
    int mySqrt(int x) {
        if(x  < 2)
            return x;
        if(x == 2)
            return 1;
        int left = 1, right = x / 2;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(x / mid == mid)
                return mid;
            else if (x / mid > mid)
                left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
