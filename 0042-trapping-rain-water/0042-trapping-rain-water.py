# Motivation: For each height We'll calculate the minimum hight of the maximum height 
#     from the left and the right. This will give us the maximum water can be traped in 
#     the current position, then we'll substract the current height to get the actual value.
#     The sum of all diffrences is the traped rain.
# Complexity: 
#     Time - O(n): Looping over the array three times.
#     Space - O(n): Storing bounds for each hieght
#
class Solution:
    def trap(self, height: List[int]) -> int:
        
        n = len(height)
        
        # the minimum value between the max of left and right bounds
        min_bound = [0 for _ in range(n)]

        # Calculate maximum left bound for each height
        max_left = 0
        for i in range(n):
            min_bound[i] = max_left
            max_left = max(max_left, height[i])

        # Calculate maximum right bound for each height
        max_right = 0
        for i in range(n - 1, -1, -1):
            min_bound[i] = min(max_right, min_bound[i])
            max_right = max(max_right, height[i])

        # sum the diffrence between the min bounds and the heights
        result = 0
        for i in range(n):
            curr_water = min_bound[i] - height[i]
            result += max(0, curr_water)
        
        return result
