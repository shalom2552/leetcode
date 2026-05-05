"""
Motivation: Bitwise on char values.
    Sum all the elements of t and substract the sum of s.
    We'll left with the char value of the extra char and we can return it.
Complexity:
    Time - O(s+t): Summing the strings.
    Space - O(1): Auxiliary.
"""
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(sum(list(bytes(t, 'ascii'))) - sum(list(bytes(s, 'ascii'))))
