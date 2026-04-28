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
        if (n < 1) {
            return false;
        } 

        int mask = 1;
        // loop on max size of int (64 / 2) 
        for (int i = 1; i < 32; ++i) {
            // is the only bit on
            if (mask == n) {
                return true;
            }
            mask <<= 2; // check next
        }

        return false;
    }
};
