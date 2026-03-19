# Motivation: Two Pointers.
#     The largest squares will always be at the edges of the sorted array (negatives or positives).
#     Use two pointers, l and r, to point to the start and end of the array.
#     Compare the absolute values of the numbers at both pointers.
#     Pick the larger one, square it, and place it at the end of the result array.
#     Move the pointer we used and the write index, then repeat until the array is filled.
# Complexity: 
#     Time - O(n): We only loop through the array once.
#     Space - O(n): To store the result array (O(1) auxiliary space if not counting the output).

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:

        # indecis to read cur max squer value
        l = 0
        r = len(nums) - 1
        write = len(nums) - 1
        res = [0] * len(nums)

        while l <= r:

            # bigger absulute value means bigger squer value
            if abs(nums[l]) > abs(nums[r]):
                res[write] = nums[l] * nums[l]
                l += 1
            else:
                res[write] = nums[r] * nums[r]
                r -= 1
            
            write -= 1

        return res
