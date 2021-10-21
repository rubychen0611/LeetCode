
// @Title: 全排列 II (Permutations II)
// @Author: rubychen0611
// @Date: 2021-10-15 17:29:08
// @Runtime: 8 ms
// @Memory: 11.2 MB

class Solution {
private:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, int cur) { // cur: 当前处理的位置
        if(cur == nums.size()) {
            ans.push_back(nums);
        }
        unordered_set<int> hashSet;
        int i = cur;
        while(i < nums.size()) {
            if(hashSet.find(nums[i]) == hashSet.end()) {
                swap(nums, cur, i);
                backTrack(nums, cur + 1);
                swap(nums, cur, i);
                hashSet.insert(nums[i]);
            }
            i ++;
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        backTrack(nums, 0);
        return ans;
    }
};
