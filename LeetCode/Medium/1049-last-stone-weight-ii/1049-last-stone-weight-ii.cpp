/*
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
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        // dp matrix: #stones x n/2 (items, capacity)
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        std::size_t items_cnt = stones.size() + 1;
        std::size_t capacity = (sum / 2) + 1;
        std::vector<std::vector<int>> dp(items_cnt, std::vector<int>(capacity));

        for (std::size_t i = 1; i < items_cnt; ++i) {
            for (std::size_t j = 0; j < capacity; ++j) {
                // -1 since dp as extra row for no items
                int weight = stones[i - 1];

                // insuficient capacity for item
                if (weight > j) {
                    // same value as not using the stone
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                int exclude_stone = dp[i - 1][j];
                int include_stone = weight + dp[i - 1][j - weight];

                // store the higher value from which to include or exclude
                dp[i][j] = std::max(exclude_stone, include_stone);
            }
        }

        // sum = p1 + p2, answer = p2 - p1 = sum - 2 * p1
        int closest_half = dp[stones.size()][sum / 2];
        return sum - 2 * closest_half;
    }
};