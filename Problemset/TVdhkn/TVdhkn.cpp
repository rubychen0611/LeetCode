
// @Title: 所有子集 (所有子集)
// @Author: rubychen0611
// @Date: 2021-10-13 20:33:59
// @Runtime: 4 ms
// @Memory: 10.6 MB

class Solution {
private:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, int i, vector<int>& subset){
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }
        backTrack(nums, i+1, subset);
        subset.push_back(nums[i]);
        backTrack(nums, i+1, subset);
        subset.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backTrack(nums, 0, subset);
        return ans;
    }
};
