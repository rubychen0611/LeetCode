
// @Title: 山峰数组的顶部 (山峰数组的顶部)
// @Author: rubychen0611
// @Date: 2021-10-12 21:09:29
// @Runtime: 0 ms
// @Memory: 11.3 MB

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(mid - 1 >= 0 && mid + 1 < arr.size()) {
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                    return mid;
                }
                else if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid + 1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else if (mid == 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
