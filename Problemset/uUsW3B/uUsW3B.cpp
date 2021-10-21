
// @Title: 含有 k 个元素的组合 (含有 k 个元素的组合)
// @Author: rubychen0611
// @Date: 2021-10-13 20:45:00
// @Runtime: 48 ms
// @Memory: 18.4 MB

class Solution {
private:
    vector<vector<int>> ans;
    int n, k;
    void backTrack(int i, vector<int>& combination) {
        if(i == n + 1) {
            return;
        }
        backTrack(i + 1, combination);
        combination.push_back(i);
        if (combination.size() == k) {
            ans.push_back(combination);
        }
        else {
            backTrack(i + 1, combination);
        }
        combination.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this -> n = n;
        this -> k = k;
        vector<int> combination;
        backTrack(1, combination);
        return ans;
    }
};
