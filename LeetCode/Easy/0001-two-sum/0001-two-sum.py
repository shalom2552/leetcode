# Motivation: num1 + num2 = target => num1 = target - num2
#       Use a hashmap to store the diff between each number and the target.
#       Loop the array and in each iteration chek if the current number - target
#       was seen before.
# Complexity: 
#     Time - O(n): Looping over the array once
#     Space - O(n): Store each element once in worst case
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        # hashmap to store values and their index
        hashmap = {}

        for i in range(len(nums)):

            # compliment is the second number to sum to target
            compliment = target - nums[i]

            # is this number has seen before
            if compliment in hashmap.keys():
                return [hashmap[compliment], i]

            # add current number to the hashmap
            hashmap[nums[i]] = i
        pass