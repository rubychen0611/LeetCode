
// @Title: 第一个错误的版本 (First Bad Version)
// @Author: rubychen0611
// @Date: 2021-01-31 23:11:25
// @Runtime: 0 ms
// @Memory: 5.8 MB

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if (!isBadVersion(mid))
                left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

