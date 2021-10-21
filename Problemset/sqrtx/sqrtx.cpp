
// @Title: x 的平方根 (Sqrt(x))
// @Author: rubychen0611
// @Date: 2021-10-17 17:05:18
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) {
            return x;
        }
        int left = 1, right = x / 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid == x / mid) {
                return mid;
            }
            else if(mid < x / mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};
