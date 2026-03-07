# Motivation: Buy and sell every day, if it worth it.
#     For every day, if the price is higher than yesterday, then we could have
#     bought it and sell today. other wise we won't buy.
# Complexity: 
#     Time - O(n): Looping over the array once.
#     Space - O(1): Auxiliary.
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        length = len(prices)

        # calculate profit from each day
        for i in range(1, length):
            today = prices[i]
            yesterday = prices[i - 1]

            # yesterday's price is lower than today's
            if yesterday < today:
                profit += today - yesterday

        return profit
