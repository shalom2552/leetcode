/*
Motivation: Using bitwise operations to check for exactly one set bit.
    If n is negative it is not a power of 2.
    Then for it to be a power of two in the binary represntation it should have
    only one set bit and the rest are 0. (n-1) flip all the bits until the 
    first set bit (including), and n 'and' (n-1) removes the first set bit.
    So if (n & (n-1)) == 0, then n has exactly one set bit, therefore 
    n is a power of 2.
Complexity: 
    Time - O(1): Simple check.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};