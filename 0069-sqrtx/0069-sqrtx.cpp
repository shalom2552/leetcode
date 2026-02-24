/*
Motivation: Binary Search on the solution space.
Complexity:
      Time - O(logx): binary search on x.
      Space - O(1): Auxiliary.
*/
class Solution {
public:
    int mySqrt(int x) {
        
        // define the search space
        int low = 0;
        int high = x;

        // binary search
        long long mid;
        while (low <= high) {

            // prevent over flow on mid calculation
            mid = low + (high - low) / 2; // 2

            // found the closest integer to sqrt(x)
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x) {
                return mid;    
            } else if (mid * mid < x) {
                // search right
                low = mid + 1;
            } else {
                // search left
                high = mid - 1;
            }
        }

        // return the closest integer if not equal
        return mid;
    }
};
