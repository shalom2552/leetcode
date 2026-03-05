/*
Motivation: Greedy approach.
      Keep track of the minimum price we have seen so far.
      Loop over the array and in every iteration update the max profit 
      by checking the diff between current price and min_price.
      Then update the min_price if the current price is smaller.
Complexity: 
    Time - O(n): looping over the array once
    Space - O(1): Only save the min_price and profit
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // 0 if no higher profit has found
        int profit = 0;

        // current minimum price
        int min_price = prices[0];

        // loop over days and find the max profit
        for (std::size_t i = 1; i < prices.size(); ++i) {

            // update max profit
            profit = std::max(profit, prices[i] - min_price);
            
            // update the min price we have seen so far
            min_price = std::min(min_price, prices[i]);
        }
        
        return profit;
    }
};


/*
Motivation: DP.
      dp[i] = max profit of selling on day i.
      Loop over the array and update the dp with the price diff from yesterday.
      If the current profit is negative we'll put 0.
      The result is the max value in the dp array.
Complexity: 
    Time - O(n): looping over the array once
    Space - O(n): Store the dp for every day
*/
class SolutionDP {
public:
    int maxProfit(vector<int>& prices) {
        
        // dp[i] = max profit of selling on day i
        std::vector<int> dp(prices.size(), 0);

        // loop over days and update the dp
        for (std::size_t i = 1; i < prices.size(); ++i) {

            // the price change from yesterday
            int diff = prices[i] - prices[i-1];

            // put 0 if there is no profit
            dp[i] = std::max(0, dp[i-1] +diff);
        }

        // max profit selling from all days
        int profit = *std::max_element(dp.begin(), dp.end());
        return profit;
    }
};