/**
 * Motivation: Iterative approach.
 *     Handle base cases for 0 and 1.
 *     Keep track of the last two Fibonacci numbers in prev and cur.
 *     Loop from 2 to n and update the numbers.
 *     We can update them without a temp variable by using simple math.
 *     The result is the sum of the last two numbers.
 * Complexity: 
 *     Time - O(n): Looping from 2 to n once.
 *     Space - O(1): Only saving the prev and cur variables.
 */

class Solution {
public:
    int fib(int n) {

        if (n == 0 || n == 1) {
            return n;
        }

        int prev = 0;
        int cur = 1;

        for (int i = 2; i < n; ++i) {
            // update cur to the next fib number
            cur = prev + cur;
            // update prev to the old cur
            prev = cur - prev;
        }

        return  prev + cur;
    }
};
