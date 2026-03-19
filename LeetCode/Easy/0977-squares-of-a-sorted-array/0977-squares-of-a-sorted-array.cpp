/**
 * Motivation: Two Pointers.
 *     The largest squares will always be at the edges of the sorted array (negatives or positives).
 *     Use two pointers, l and r, to point to the start and end of the array.
 *     Compare the absolute values of the numbers at both pointers.
 *     Pick the larger one, square it, and place it at the end of the result array.
 *     Move the pointer we used and the write index, then repeat until the array is filled.
 * Complexity: 
 *     Time - O(n): We only loop through the array once.
 *     Space - O(n): To store the result array (O(1) auxiliary space if not counting the output).
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
                
        // indecis to read cur max squer value
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res(nums.size());

        // write from the end
        for (int write = nums.size() - 1; write >= 0; --write) {
            int left_val = nums[l] * nums[l];
            int right_val = nums[r] * nums[r];

            // bigger absulute value means bigger squer value
            if (left_val > right_val) {
                res[write] = left_val;
                ++l;
            } else {
                res[write] = right_val;
                --r;
            }
        }

        return res;
    }
};
