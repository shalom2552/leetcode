"""
Motivation: Binary Search.
    We know that sqrt(x) < x/2 for all x > 4
    Therefore we can do a binary search on the search space (4, num/2]
Complexity:
    Time - O(log(num)): Binary Search up to n/2
    Space - O(1): Auxiliary
"""
class Solution:
    def isPerfectSquare(self, num: int) -> bool:

        # we search from 4 so we must check 1 and 4 first
        if (num == 1 or num == 4):
            return True

        # sqrt(x) < x/2 for all x > 4
        left = 1
        right = num // 2

        # binary search on the search space
        while left <= right:

            mid = left + (right - left) // 2
            sqr = mid * mid

            # found integer sqrt(num)
            if sqr == num:
                return True

            if sqr < num:
                left = mid + 1
            else:
                right = mid - 1
        
        return False
