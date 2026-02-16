# Motivation: Naive approach, using hash map to store all elements count.
#       Return all elements that appears mor than n/3 times. 
# Complexity: 
#     Time - O(n): Loop over the array once.
#     Space - O(n): Hash map for all elements, n in worst case.
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:

        # hash map to store counts
        counts = {}

        # list to store the results
        result = []
        
        # count how many times each number appears
        for num in nums:
            if num not in counts:
                counts[num] = 1
            else:
                counts[num] += 1
        
        # add all elements that apears more than n/3 to the result
        for num, count in counts.items():
            if count > len(nums) // 3:
                result.append(num)

        return result