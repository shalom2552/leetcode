/*
Motivation: Loop over the list once and update it in place.
      Use two pointer to indicate the right and left edges of the array.
      If we see 0 We'll swap it with the left and increase left by 1.
      If we see 1 we keep it and just andvace.
      If we see 2 we swap with the right and only reduce right by 1.
Complexity: 
    Time - O(n): looping over the array once
    Space - O(1): We change the array in place
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Writers to write 0 and 2
        int left = 0;
        int right = nums.size() - 1;
        
        // Loop over the array and swap 0 and 2 to edges
        int read = 0;
        while (read <= right) {

            if (nums[read] == 0) {
                // swap current '0' with the element at left
                swap_elements(nums, left, read);
                left += 1;
                read += 1;
            }
            
            else if (nums[read] == 1) {
                // just keep reading it'll swap if needed
                read += 1;
            }

            else {
                // swap current '2' with the element at right
                swap_elements(nums, right, read);
                right -= 1;
            }
        }
    }

    void swap_elements(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

};
