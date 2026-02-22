class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        # Can't profit from one day or less
        if len(prices) < 1:
            return 0

        profit = 0

        # calculate profit from each day
        for i in range(1, len(prices)):

            # today's price is lower than yesterday's
            if prices[i - 1] < prices[i]:
                profit += prices[i] - prices[i - 1]

        return profit
            
            


        