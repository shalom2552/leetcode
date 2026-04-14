"""
Motivation: 0/1 Knapsack (DP).
      The result of smashing all stones equals the difference between two
      partitions. Every stone gets a + or - sign, so we want to split the
      stones into two groups with the closest possible sum.
      Use a knapsack DP where each stone's weight and value are the same.
      The capacity is total_sum / 2. Find the heaviest subset that fits,
      then the answer is total_sum - 2 * subset_sum.
Complexity: 
    Time - O(n * s): Looping over stones and capacities.
    Space - O(n * s): The DP matrix.
Where n is the number of stones and s is total_sum / 2.
"""
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        
        # dp matrix: #stones x n/2 (items, capacity)
        sum_weights = sum(stones)
        items_cnt = len(stones) + 1
        capacity = (sum_weights // 2) + 1
        dp = [[0] * capacity for _ in range(items_cnt)]

        for i in range(1, items_cnt):
            for j in range(capacity):
                # -1 since dp as extra row for no items
                weight = stones[i - 1]

                # insuficient capacity for item
                if weight > j:
                    # same value as not using the stone
                    dp[i][j] = dp[i - 1][j]
                    continue

                exclude_stone = dp[i - 1][j]
                include_stone = weight + dp[i - 1][j - weight]

                # store the higher value from which to include or exclude
                dp[i][j] = max(exclude_stone, include_stone)

        # sum = p1 + p2, answer = p2 - p1 = sum - 2 * p1
        closest_half = dp[items_cnt - 1][capacity - 1]
        return sum_weights - 2 * closest_half
