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
