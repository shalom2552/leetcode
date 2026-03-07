/*
Motivation: Dynamic Planing. Save last two calculated values in the array,
    in each iteration ccchoose wheter to include corrent number or use the
    sum of prevoius position sum, or the ccurrent value (in case of negative sum).
Complexity:
    Time - O(n): Looping the array once.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
    
    if (nums.size() == 0) {
		return 0;
	}

    if (nums.size() == 1) {
		return std::max(0, nums[0]);
	}

	std::vector<int> dp(nums.size());

	// base cases, max with 0 in case of negative numbers
	dp[0] = std::max(0, nums[0]);
	dp[1] = std::max(dp[0], nums[1]);

	// for each position find the max sum up to i
	for (std::size_t i = 2; i < nums.size(); ++i) {

		// is it better to use this number or the previous
		dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);

		// in case of negative previous sum, only take current value
		dp[i] = std::max(dp[i], nums[i]);
	}

	// max calculated sum for last position
	return dp[nums.size() - 1];
    }
};