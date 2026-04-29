/*
Motivation: Bit manipulation.
    Assuming int is 32 bit size.
    Split the bits into two halves and swap them, then repeat for smaller halves.
    We do this 5 times until every bit is in its reversed position.
    Each time, use a mask to get the right bits, 
    shift them to where they belong, and do OR to get the full result.
Complexity: 
    Time - O(1): 5 tomes constant bit operations.
    Space - O(1): Only saving the 5 masks.
*/
class Solution {
public:
    int reverseBits(int n) {
    n = ((n & 0xFFFF0000) >> 16) | ((n & ~0xFFFF0000) << 16);
    n = ((n & 0xFF00FF00) >> 8)  | ((n & ~0xFF00FF00) << 8);
    n = ((n & 0xF0F0F0F0) >> 4)  | ((n & ~0xF0F0F0F0) << 4);
    n = ((n & 0xCCCCCCCC) >> 2)  | ((n & ~0xCCCCCCCC) << 2);
    n = ((n & 0xAAAAAAAA) >> 1)  | ((n & ~0xAAAAAAAA) << 1);
    return n;
    }
};
