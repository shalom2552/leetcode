/*
Motivation: num1 + num2 = target => num1 = target - num2
      Use a hashmap to store the diff between each number and the target.
      Loop the array and in each iteration chek if the current number - target
      was seen before.
Complexity: 
    Time - O(n): Looping over the array once
    Space - O(n): Store each element once in worst case
*/        
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                
        // Hashmap to store values and their index
        std::unordered_map<int, int> hashmap;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {

            // Compliment is the second number to sum to target
            int compliment = target - nums[i];

            // is this number has seen before
            if (hashmap.count(compliment) > 0) {
                result = {hashmap[compliment], i};
                return result;
            }

            // add current number to the hashmap
            hashmap[nums[i]] = i;
        }
        return result;
    }
};