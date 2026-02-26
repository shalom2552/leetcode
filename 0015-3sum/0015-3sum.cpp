/*
Motivation: Sort the array and then an outer for loops and use two pointers.
      In each iteration, while skiping duplicate numbers, we check each pair 
      in the rest of the array, if the total is less than 0, we increment from 
      the left to get a bigger value and vise versa. If the total is 0 than we 
      can safly add this result since the array is sorted and we skip duplicates.  
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

            // skip duplicate consecutive numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // two pointers to scan the array
            std::size_t l = i + 1;
            std::size_t r = nums.size() - 1;

            // search from both side of the array
            while (l < r) {

                int total = nums[i] + nums[l] + nums[r];

                // need a bigger number increase from left
                if (total < 0) {
                    ++l;
                }
                // need a smaller number decrease from right
                else if (total > 0) {
                    --r;
                }
                // total == 0
                else {
                    // not duplicates, since the array is sorted and we skip duplicate
                    results.push_back( {nums[i], nums[l], nums[r]} );
                    
                    // keep searching with diffrent values 
                    ++l;
                    --r;

                    // find the next diffrent values from both ends
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
            }
        }
        
        // if nums is empty while condition is false and results is empty 
        return results;
    }
};
