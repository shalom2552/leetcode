# Motivation: Loop over the list once and update it in place.
#       Use two pointer to indicate the right and left edges of the array.
#       If we see 0 We'll swap it with the left and increase left by 1.
#       If we see 1 we keep it and just andvace.
#       If we see 2 we swap with the right and only reduce right by 1.
# Complexity: 
#     Time - O(n): looping over the array once
#     Space - O(1): We change the array in place
class Solution:
    def sortColors(self, nums: List[int]) -> None:

        # writers to write 0 and 2
        left = 0
        right = len(nums) - 1
        
        # Loop over the array and swap 0 and 2 to edges
        read = 0
        while read <= right:

            if nums[read] == 0:
                # swap current '0' with the element at left
                nums[left], nums[read] = nums[read], nums[left]
                left += 1
                read += 1
            
            elif nums[read] == 1:
                # just keep reading it'll swap if need
                read += 1

            else:
                # swap current '2' with the element at right
                nums[right], nums[read] = nums[read], nums[right]
                right -= 1

        return
