
// @Title: 变位词组 (变位词组)
// @Author: rubychen0611
// @Date: 2021-10-10 10:48:44
// @Runtime: 28 ms
// @Memory: 20.2 MB

bool cmp(char a, char b) {
    return a < b;
}
class Solution {
private:
    unordered_map<string, int> wordToIndex;
    vector<vector<string>> ans;
    string sortString(string& str) {
        string sorted_str(str);
        sort(&sorted_str[0], &sorted_str[sorted_str.length()] , cmp);
        return sorted_str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string str: strs) {
            string sorted_str = sortString(str);
            if(wordToIndex.find(sorted_str) != wordToIndex.end()) {
                ans[wordToIndex[sorted_str]].push_back(str);
            }
            else {
                vector<string> group = {str};
                ans.push_back(group);
                wordToIndex.insert(pair<string, int>(sorted_str, ans.size() - 1));
            }
        }
        return ans;
    }
};
