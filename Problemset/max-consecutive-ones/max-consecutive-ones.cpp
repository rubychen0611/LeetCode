
// @Title: 最大连续 1 的个数 (Max Consecutive Ones)
// @Author: rubychen0611
// @Date: 2021-02-15 14:11:53
// @Runtime: 52 ms
// @Memory: 32.7 MB

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                count ++;
            else{
                if(max < count)
                    max = count;
                count = 0;
            }
        }
        if (max < count)
            max = count;
        return max;
    }
};
