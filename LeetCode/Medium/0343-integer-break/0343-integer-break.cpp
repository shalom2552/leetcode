/**
 * Motivation: DP + LUT.
 *     Use Tabulation DP to precalcculate the 58 n solutions.
 *     Return the solution from the LUT.
 *     In the building function we starting from the botom constructing the LUT,
 *     for each k we loop over the previous values and find the max break, it can
 *     the number itself or it's dp value.
 * Complexity: 
 *     Time - O(1): Array subscript.
 *     Space - O(58): The LUT.
 * Complexity of DP (58 times):
 *     Time - O(n^2): Building the LUT.
 *     Space - O(n): The DP array.
 */

class Solution {
public:
    int integerBreak(int n) {
        return LUT[n];        
    }

    /**
    * @brief DP Tabulation for creating the LUT.
    * Calculate the 58 solutions using DP and store in LUT. 
    * dp[k] = max_i(i * max(k - i, dp[k - i]))
    */
    void build_integer_break_LUT() {
        // loop over input options
        for (int k = 2; k <= N; ++k) {
            int max_break = INT_MIN;
            // find max break using previus calculated
            for (int i = 1; i < k; ++i) {
                // max break using the number it self or its max calculated break
                int cur_break = i * std::max(k - i, LUT[k - i]);
                max_break = std::max(max_break, cur_break);

            }
            // update the LUT
            LUT[k] = max_break;
        }
    }

private:
    const int N = 58;
    std::vector<int> LUT = {
        1, 1, 1, 2, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 162, 243,
        324, 486, 729, 972, 1458, 2187, 2916, 4374, 6561, 8748, 13122, 19683, 26244,
        39366, 59049, 78732, 118098, 177147, 236196, 354294, 531441, 708588, 1062882,
        1594323, 2125764, 3188646, 4782969, 6377292, 9565938, 14348907, 19131876,
        28697814, 43046721, 57395628, 86093442, 129140163, 172186884, 258280326,
        387420489, 516560652, 774840978, 1162261467, 1549681956
    };
};
