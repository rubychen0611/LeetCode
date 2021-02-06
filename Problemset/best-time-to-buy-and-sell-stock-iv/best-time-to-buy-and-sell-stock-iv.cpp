
// @Title: 买卖股票的最佳时机 IV (Best Time to Buy and Sell Stock IV)
// @Author: rubychen0611
// @Date: 2021-02-03 14:00:35
// @Runtime: 12 ms
// @Memory: 10.4 MB

class Solution {
private:
    int max (int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        if (k > n)
        {
            int max_profit = 0;
            for (int i = 0; i < prices.size()-1; i++)
            {
                if (prices[i+1] - prices[i] > 0)
                    max_profit += prices[i+1] - prices[i];
            }
            return max_profit;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};

