
// @Title: 分发饼干 (Assign Cookies)
// @Author: rubychen0611
// @Date: 2021-01-24 18:02:34
// @Runtime: 64 ms
// @Memory: 17.1 MB

bool compare(int a, int b) {
    return a > b;
}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end(), compare);
        int ans = 0;
        for (int i = 0; i < g.size(); i++)
        {
            while(!s.empty() && s.back() < g[i])
                s.pop_back();
            if (!s.empty())
            {
                ans++;
                s.pop_back();
            }
            else break;
        }
        return ans;
    }
};

