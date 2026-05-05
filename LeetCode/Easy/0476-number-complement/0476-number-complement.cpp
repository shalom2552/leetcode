/*
Motivation: Bit Manipulation.
    Get a mask of the bits until the Most segnificant set bit in num.
    Calculate this mask by starting on all bits as set and shift to left
    until the mask & number is not 0, then negate the bits to get the mask.
    When mask & number == 0: it means we past the MSB of num, then we just negate it.
    Return the mask and the negate num, that is the complement until the MSB in num.
Complexity:
    Time - O(sizeof(int)*8): Looping at integer bits.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    int findComplement(int num) {
        int mask = -1;
        for (; mask & num; mask <<= 1);
        return ~num & ~mask;
    }
};