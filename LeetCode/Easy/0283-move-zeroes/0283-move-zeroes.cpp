/**
 * Motivation: Two-pointers.
 *     Keep read and write indices, scan the array once using the read index, 
 *     and write each non zero number to the write index and andvace the write index.
 *     Finaly write 0's on the rest.
 * Complexity: 
 *     Time - O(n): Looping over the array twice.
 *     Space - O(1): Changing in place.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        size_t write = 0;
        size_t len = nums.size();

        // shift all non-zero to left
        for (size_t read = 0; read < len; ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }

        // write 0 on the rest
        for (size_t i = write; i < len; ++i) {
            nums[i] = 0;
        }
    }
};