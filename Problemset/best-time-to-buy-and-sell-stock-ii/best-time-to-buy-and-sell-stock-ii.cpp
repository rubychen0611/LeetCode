
// @Title: 买卖股票的最佳时机 II (Best Time to Buy and Sell Stock II)
// @Author: rubychen0611
// @Date: 2021-01-25 14:07:48
// @Runtime: 4 ms
// @Memory: 12.6 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i+1] - prices[i] > 0)
                ans += prices[i+1] - prices[i];
        }
        return ans;
    }
};

