
// @Title: 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)
// @Author: rubychen0611
// @Date: 2021-02-03 13:29:24
// @Runtime: 144 ms
// @Memory: 73.3 MB

class Solution {
private:
    int max (int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; i++)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

