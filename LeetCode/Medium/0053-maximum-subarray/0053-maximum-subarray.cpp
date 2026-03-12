/*
Motivation: Kadane's Algorithm.
      Loop over the array and keep track of the sum up to the current number.
      If the previous sum is positive, we add the current number to it 
      because it helps us. If the previous sum is negative, it hurts our sum so
      it's better to just start a new sum from the current number.
      In every step update the max sum we have seen so far.
Complexity: 
    Time - O(n): looping over the array once
    Space - O(1): We only save the current sum and max sum variables
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        size_t arr_size = nums.size();
        
        // size 0 has no sum
        if (arr_size == 0 ) {
            return 0;
        }

        // max sum until curr nums
        int prev = nums[0];
        int max_sum = prev;

        // loop over nums and find sub array with max sum
        for (size_t i = 1; i < arr_size; ++i) {
            // if the sum up to now is negative start new sum
            if (prev > 0) {
                prev += nums[i];
            } 
            // add cur num to the sum
            else {
                prev = nums[i];
            }

            // update max sum
            max_sum = max(max_sum, prev);
        }

        return max_sum;
    }
};