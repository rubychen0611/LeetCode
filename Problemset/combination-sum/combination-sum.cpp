
// @Title: 组合总和 (Combination Sum)
// @Author: rubychen0611
// @Date: 2021-10-15 15:58:06
// @Runtime: 64 ms
// @Memory: 16.7 MB

class Solution {
private:
    int target;
    vector<vector<int>> ans;
    void backTrack(vector<int>& candidates, int i, vector<int> &combination, int curSum) {
        cout << endl;
        if (i == candidates.size()) {
            return;
        }
        // not use candidates[i]
        backTrack(candidates, i + 1, combination, curSum);
        // use candidates[i]
        combination.push_back(candidates[i]);
        curSum += candidates[i];
        if(curSum == target) {
            ans.push_back(combination);
        }
        else if(curSum < target) {
            backTrack(candidates, i, combination, curSum);
           // backTrack(candidates, i+1, combination, curSum); 多余
        }
        combination.pop_back();
        curSum -= candidates[i];
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this -> target = target;
        vector<int> combination;
        backTrack(candidates, 0, combination, 0);
        return ans; 
    }
};
