/**
 * Motivation: Greedy.
 *     For each position find the max jump that can be made from this position.
 *     Update the greedy value, if it becoms 0 midway, we stuck and return 0.
 *     If the number of jumps beffor the last one is grather than 0, return true.
 * Complexity:
 *     Time - O(n): Loop over nums.
 *     Space - O(1): Auxiliary.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {

        // base case
        if (nums.size() == 1) {
            return true;
        }

        // greedy search
        int jumps = nums[0];
        for (size_t i = 1; i < nums.size() - 1; ++i) {

            // stuck, cant jump
            if (jumps == 0) {
                return false;
            }

            // max jump from curr position
            jumps = max(jumps - 1, nums[i]);
        }
        
        // can get to last
        return jumps > 0;
    }
};

/**
 * Motivation: DP.
 *     For each position save the max jump that can be made from this position.
 *     Update dp[i], if dp[i-1] == 0, we stuck and return 0.
 *     If the number of jumps beffor the last one is grather than 0, return true.
 * Complexity:
 *     Time - O(n): Loop over nums.
 *     Space - O(n): The DP array.
 */
class SolutionDP {
public:
    bool canJump(vector<int>& nums) {

        // can reach to it self
        if (nums.size() == 1) {
            return true;
        }

        size_t n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (size_t i = 1; i < n; ++i) {
            // stuck, cant jump
            if (dp[i - 1] == 0) {
                return false;
            }
            dp[i] = max(dp[i - 1] - 1, nums[i]);
        }
        
        return dp[n - 2] > 0;
    }
};