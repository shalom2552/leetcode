class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // dp[i] = max profit of selling on day i
        vector<int> dp(prices.size(), 0);

        // loop over days and update the dp
        for (size_t i = 1; i < prices.size(); ++i) {

            // the price change from yesterday
            int diff = prices[i] - prices[i-1];

            // put 0 if there is no profit
            dp[i] = max(0, dp[i-1] +diff);
        }

        // max profit selling from all days
        int profit = *max_element(dp.begin(), dp.end());
        return profit;
    }
};