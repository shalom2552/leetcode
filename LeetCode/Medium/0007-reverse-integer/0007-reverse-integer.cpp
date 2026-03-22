/**
 * Motivation: Iterative digit extraction.
 *     Using a long variable to prevent overflow. Loop while x still has digits (x != 0).
 *     In each iteration, extract the last digit of x using modulo (% 10).
 *     Multiplying by 10 to shift the reversed digits to the left and add the new digit.
 *     Finally, check if the reversed value is out of int range and return 0 if so.
 * Complexity: 
 *     Time - O(log n): Loop over digits in x, log_10(n).
 *     Space - O(1): Auxiliary.
 */
 class Solution {
public:
    int reverse(int x) {
        
        long reversed = 0;

        // while x has valid digits
        while (x != 0) {
            // add x's right digit to the right of reversed
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // return 0 if int overflow
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }

        // implicit cast to int
        return reversed;
    }
};
