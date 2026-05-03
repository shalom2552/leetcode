"""
Motivation: GCD and Bezout's Identity.
    The water we can measure is a multiple of the GCD of the two capacities.
    We check if the target is multiple by their GCD and not greater than their sum.
Complexity:
    Time - O(log(n)): The GCD (deviding by more then half each iteration).
    Space - O(log(n)): The recursion stack.
Where n = min(x,y).
We can also solve this using BFS on all jug states in O(x * y).
"""
class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if target > x + y: return False
        return target % self.gcd(max(x, y), x + y - max(x, y)) == 0

    def gcd(self, a: int, b: int) -> int:
        return a if b == 0 else self.gcd(b, a % b)
