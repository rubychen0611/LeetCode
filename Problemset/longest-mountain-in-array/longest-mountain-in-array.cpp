
// @Title: 数组中的最长山脉 (Longest Mountain in Array)
// @Author: rubychen0611
// @Date: 2021-02-17 13:48:38
// @Runtime: 12 ms
// @Memory: 19.4 MB

class Solution {
private:
    int decideSign(int a, int b)
    {
        if(a < b)
            return 1;
        else if (a == b)
            return 0;
        else return -1;
    }
public:
    int longestMountain(vector<int>& arr) {
        vector<pair<int, int>> signs;
        for(int i = 1; i < arr.size(); i++)
        {
            int sign = decideSign(arr[i-1], arr[i]);
            if(i == 1 || signs.back().first != sign)
                signs.push_back(pair<int,int>{sign, 1});
            else
            {
                if(signs.back().first == sign)
                    signs.back().second ++;
            }
        }
        int ans = 0;
        for(int i = 1; i < signs.size(); i++)
        {
            if(signs[i-1].first == 1 && signs[i].first == -1)
            {
                int len = signs[i-1].second + signs[i].second + 1;
                if(len > ans)
                    ans = len;
            }
        }
        return ans;
    }
};
