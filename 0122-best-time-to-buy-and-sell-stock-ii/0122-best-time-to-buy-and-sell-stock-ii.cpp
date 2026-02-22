/*
Motivation: Buy and sell every day, if it worth it.
    For every day, if the price is higher than yesterday, then we could have
    bought it and sell today. other wise we won't buy.
Complexity: 
    Time - O(n): Looping over the array once.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // calculate profit from each day
        for (int i = 1; i < prices.size(); ++i) {
            // yesterday's price is lower than today's
            if (prices[i - 1] < prices[i]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
