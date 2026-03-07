/*
Motivation: Mark each value in the array is exsitied by modifing thee atrray in place.
    Valid result values are 1 up to the size of the array + 1.
    Loop over the array three times, at first ignore all negative numbers by marking 
    them as 0. Then loop over the array again and for each valid value mark the value
    at the position of the index it represents as negative value. Finally, loop one more
    time, if we see a positive value, that means we didn't find a value of the current
    index. there for its the result, otherwise the result is the next valid value, (n + 1).
Complexity: 
    Time - O(n): Looping over the array three times.
    Space - O(1): Auxiliary space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // set all negative values to 0
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }

        // mark all exisitng elements as negative at the index equal to their element value
        for (std::size_t i = 0; i < nums.size(); ++i) {
            
            // get the absulute value, in case it has been changed by prevoius one.
            int val = abs(nums[i]);
            
            // if the number is not in the range, just skip it
            if (val < 1 || val > nums.size()) {
                continue;
            }

            // if of the number is 0 set it to an invalid negative value
            if (nums[val - 1] == 0) {
                nums[val - 1] = (-1) * (nums.size() + 1);
            }
            // mark the value at the index that equal to the element as negative
            else if (nums[val - 1] > 0) {
                nums[val - 1] *= (-1);
            }
        }

        // loop over the list again to find the missing number
        // if a value is in the array we already seted it to negative value
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        
        // first missing positive number is not int [1, n]
        return (int)(nums.size()) + 1;
    }
};