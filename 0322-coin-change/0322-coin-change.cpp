/*
Motivation: Dynamic Planing. We do a bottom up DP, starting from 1 up to amount
    (dp[0] = 0 base case) for each number, loop over the coins and check if the 
    coin is smaller than the number and reduce it, and update the count.
    Eventually the dp array will store the min count to sum to amount or the 
    default value (no path found). 
Complexity: 
    Time - O(n*m): looping the coins for each number.
    Space - O(n): The dp array for all the numbers.
Where n is amount and m is number of coins.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    // initialize vector of x+1 (invalid) as count of sums for each number up to x
	std::vector<int> dp(amount + 1, amount + 1);

	// base case
	dp[0] = 0;

	// Bottom-Up DP
	for (int i = 1; i <= amount; ++i) {
		for (int coin : coins) {

			// cehck wheter using the coin in this value is better
			int reminder = i - coin;
			if (reminder >= 0) {
				dp[i] = std::min(dp[i], 1 + dp[reminder]);
			}
		}
	}

	// if sp[x] is INT_MAX, no path found
	return (dp[amount] < amount + 1) ? dp[amount] : -1;
    }
};