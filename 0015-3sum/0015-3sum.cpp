/*
Motivation: Sort the array and then an outer for loops and use two pointers.
Complexity: 
      Time - O(n^2): sorting and scan the array twice.
      Space - O(1): Auxiliary.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // sort the array
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;
        
        for (std::size_t i = 0; i < nums.size(); ++i) {
            
            // two pointers to scan the array
            std::size_t j = i + 1;
            std::size_t k = nums.size() - 1;

            // skip duplicate consecutive numbers
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }

            // search from both side of the array
            while (j < k) {

                int total = nums[i] + nums[j] + nums[k];

                if (total == 0) {
                    results.push_back( {nums[i], nums[j], nums[k]} );
                    
                    // keep searching with diffrent values 
                    j += 1;
                    k -= 1;

                    // find the next diffrent values from both ends
                    while (nums[j] == nums[j-1] and j < k) {
                        j += 1;
                    }
                    while (nums[k] == nums[k+1] and j < k) {
                        k -= 1;
                    }
                }
                // increase from left
                else if (total < 0) {
                    j += 1;
                }
                // decrease from right
                else {
                    k -= 1;
                }
            }
        }
            
        return results;
    }
};
