/*
Motivation: Dynamic Programing.
    dp[i][j] = can we reach to stone i with jump of size j-1, j, j+1.
    We can jump to the first stone with jump size 1 unit. Then loop over all
    stones and look back at all of the preevious stones and calculate the distances.
    In each iteration update the table dp[curr][distance] if we can arrive to prev
    stone with jump of the distance from curr stone (-+1).
    Eventually, loop over all possible jumps to last stone, if one is true 
    return true, or false otherwise.
Complexity: 
    Time - O(n^2): Loop over all stones, and all previous stones each time.
    Space - O(n^2): The table of possible jumps.
*/

class Solution {
public:
    bool canCross(vector<int>& stones) {

        size_t n = stones.size();

        // true if you can arrive to i with last jump = j
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // can jump to first stone with 1 unit
        dp[0][1] = true;

        // Bottom-Up (Tabulation)
        for (size_t stone = 0; stone < n; ++stone) {
            for (int i = stone - 1; i >= 0; --i) {
                
                // distance from this stone to prev one
                size_t skip = stones[stone] - stones[i];
                
                // pruning: can't jump. in each stone the jump increases by at most 1
                if (skip > i + 1) {
                    break;
                }

                // can jump to stone iff can jump to prev one with k-1 or k or k+1 jump
                dp[stone][skip] = dp[i][skip - 1] || dp[i][skip] || dp[i][skip + 1];
            }
        }

        // is there any jump we can make to last stone
        for (size_t skip = 1; skip < n; ++skip) {
            if (dp[n - 1][skip]) {
                return true;
            }
        }
        
        // no path found
        return false;
    }
};
