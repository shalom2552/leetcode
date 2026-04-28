/*
Motivation: Bit manipulation.
    Power of 4 in bit represantation is where only one bit is on,
    and it is in odd position (if counting from 1).
    Then we loop on the max int size (64), 32 times and each iteration,
    check if its the only bit using a mask, and shift the mask twice.      
Complexity: 
    Time - O(32): looping throgh the bits in jumps of 2.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    bool isPowerOfFour(int n) {

        // pwer of 4 must be positive
        if (n < 1) return false;

        // shift mask first bit in jumps of 2
        for(int mask = 1; mask; mask <<= 2) {
            // is the only bit on
            if (mask == n) return true;
        }

        return false;
    }
};
