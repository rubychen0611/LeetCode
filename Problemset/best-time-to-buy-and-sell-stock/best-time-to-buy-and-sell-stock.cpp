
// @Title: 买卖股票的最佳时机 (Best Time to Buy and Sell Stock)
// @Author: rubychen0611
// @Date: 2021-01-25 01:06:09
// @Runtime: 128 ms
// @Memory: 91.1 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - min_price > max_profit)
                max_profit = prices[i] - min_price;
            if(prices[i] < min_price)
                min_price = prices[i];
        }
        return max_profit;

    }
};

