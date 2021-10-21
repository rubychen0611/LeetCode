
// @Title: 全排列 (Permutations)
// @Author: rubychen0611
// @Date: 2021-10-15 16:57:42
// @Runtime: 4 ms
// @Memory: 7.8 MB

class Solution {
private:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, int cur) {
        if(cur == nums.size()) {
            ans.push_back(nums);
        }
        for(int i = cur; i < nums.size(); i++) {
            swap(nums, cur, i);
            backTrack(nums, cur + 1);
            swap(nums, cur, i);
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        if (i == j) {
            return;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums, 0);
        return ans;
    }
};
