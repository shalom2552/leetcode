/*
Motivation: GCD and Bezout's Identity.
    The water we can measure is a multiple of the GCD of the two capacities.
    We check if the target is multiple by their GCD and not greater than their sum.
Complexity:
    Time - O(log(n)): The GCD (deviding by more then half each iteration).
    Space - O(log(n)): The recursion stack.
Where n = min(x,y).
We can also solve this using BFS on all jug states in O(x * y).
*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        return !(target % gcd(max(x, y), x + y - max(x, y)));
    }

    /* find the gcd of a and b */
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};