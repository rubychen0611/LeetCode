
// @Title: 最多能完成排序的块 (Max Chunks To Make Sorted)
// @Author: rubychen0611
// @Date: 2020-12-22 17:09:42
// @Runtime: 0 ms
// @Memory: 7.4 MB

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > cur_max)
                cur_max = arr[i];
            if (cur_max == i)
                count ++;
        }
        return count;
    }
};

