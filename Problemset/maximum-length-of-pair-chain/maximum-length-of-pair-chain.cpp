
// @Title: 最长数对链 (Maximum Length of Pair Chain)
// @Author: rubychen0611
// @Date: 2021-02-04 23:16:45
// @Runtime: 312 ms
// @Memory: 59.6 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
//    int findLongestChain(vector<vector<int>>& pairs) {
//        int n = pairs.size();
//        if (n < 2)
//            return n;
//        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) -> bool {
//            if (a[0] != b[0])
//                return a[0] < b[0];
//            else return a[1] < b[1];
//        });
//
//        vector<int> dp(n, 1);
//        for(int i = 1; i < n; i++)
//        {
//            for(int j = 0; j < i; j++)
//            {
//                if(pairs[j][1] < pairs[i][0])
//                    dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//        return dp[n-1];
//    }
    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n = pairs.size();
        if (n < 2)
            return n;
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) -> bool {
            return a[1] < b[1];
        });
        int ans = 0;
        int cur = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if (pairs[i][0] > cur)
            {
                ans ++;
                cur = pairs[i][1];
            }
        }
        return ans;
    }
};

