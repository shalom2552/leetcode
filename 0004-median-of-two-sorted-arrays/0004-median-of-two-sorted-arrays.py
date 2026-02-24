# Motivation: Binary Search on the solution space.
#     The median is the max value in n / 2 smallest elementens.
#     In each iteration split A and B suche that,
#     the numbers of elements in the left side of A plus the right side of
#     B are equal to the numbers of elements in the right side of A
#     plus the left side of B:
#       1. len(A_left) + len(B_right) = len(A_right) + len(B_left)
#       2. max(A_left, B_left) < min(B_right, B_right)
#     then recursively run this until conditions are satisfied
#     The median is min(A_right, B_right)
# Complexity:
#     Time - O(logn): Binary Search.
#     Space - O(1): Auxiliary.

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        # solve assuming nums1 is the smaller array
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        # Define lengths for easy access and reduce calulations
        len_1 = len(nums1)
        len_2 = len(nums2)
        N = len_1 + len_2

        # initial search space
        low = 0
        high = len_1

        # binary search for median
        while low <= high:

            # mid values such that lengths are equal
            mid_1 = low + (high - low) // 2
            mid_2 = ((N + 1) // 2) - mid_1

            # fix out of bounds using inf values
            left_1 = nums1[mid_1 - 1] if mid_1 > 0 else float("-infinity")
            right_1 = nums1[mid_1] if mid_1 < len_1 else float("infinity")
            left_2 = nums2[mid_2 - 1] if mid_2 > 0 else float("-infinity")
            right_2 = nums2[mid_2] if mid_2 < len_2 else float("infinity")

            # if both halfs are sorted found the median
            if left_1 <= right_2 and left_2 <= right_1:
                # calculate the median based on if its odd or even
                if N % 2:
                    return max(left_1, left_2)
                else:
                    return (max(left_1, left_2) + min(right_1, right_2)) / 2
                break
            # median is too big
            elif right_1 < left_2:
                low = mid_1 + 1
            # median is too small
            else:
                high = mid_1 - 1
            
        # default return value (never reaches)
        return 0.0
