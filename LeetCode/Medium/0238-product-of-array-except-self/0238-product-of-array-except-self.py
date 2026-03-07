# Motivation:
# We calculate in a list the prefix multiplication of each element and store it.
# Same for postfix.
# Return the mulitplication of both lists  

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        # Initialize for 1 for multiplication
        prefix = 1
        suffix = 1
        res = [1] * n

        # Using the motivation above but in a fancy way
        # we calculate from both directions simultaneously
        for i in range(len(nums)):
            res[i] *= prefix        # Mutiply prifex up until i
            prefix *= nums[i]       # Update prefix
            res[n - i - 1] *= suffix
            suffix *= nums[n - i - 1]

        return res
