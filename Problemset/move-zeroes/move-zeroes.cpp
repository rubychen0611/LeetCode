
// @Title: 移动零 (Move Zeroes)
// @Author: rubychen0611
// @Date: 2021-02-17 13:35:25
// @Runtime: 4 ms
// @Memory: 8.6 MB

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] != 0)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
    }
};
