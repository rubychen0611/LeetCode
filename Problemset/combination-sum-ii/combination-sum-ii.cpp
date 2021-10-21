
// @Title: 组合总和 II (Combination Sum II)
// @Author: rubychen0611
// @Date: 2021-10-15 16:27:31
// @Runtime: 4 ms
// @Memory: 13.4 MB

class Solution {
private:
    int target;
    vector<vector<int>> ans;
    void backTrack(vector<int>& candidates, int i, vector<int>& combination, int curSum) {
        if(curSum > target) {
            return;
        }
        if(curSum == target) {
            ans.push_back(combination);
            return;
        }
        if(i >= candidates.size()) {
            return;
        }
        int next = i + 1;
        while(next < candidates.size() && candidates[next] == candidates[i]) {
            next ++;
        } 
        backTrack(candidates, next, combination, curSum);
        combination.push_back(candidates[i]);
        curSum += candidates[i];
        backTrack(candidates, i + 1, combination, curSum);
        combination.pop_back();
        curSum -= candidates[i];
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this -> target = target;
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        backTrack(candidates, 0, combination, 0);
        return ans;
    }
};
