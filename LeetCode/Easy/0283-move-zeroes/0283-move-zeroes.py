"""
Motivation: Two-pointers.
    Keep read and write indices, scan the array once using the read index, 
    and write each non zero number to the write index and andvace the write index.
    Finaly write 0's on the rest.
Complexity: 
    Time - O(n): Looping over the array twice.
    Space - O(1): Changing in place.
"""
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        
        write = 0
        length = len(nums)

        # shift all non-zero to left
        for read in range(0, length):
            if nums[read] != 0:
                nums[write] = nums[read]
                write += 1

        # write 0 on the rest
        nums[write:] = [0] * (length - write)
