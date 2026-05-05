/*
Motivation: Bit Manipulation.
    Using xor, save the bits whice x, y are diffrent.
    Calculate the number of set bits using n & (n-1),
    which unset the least segnificant set bit.
Complexity:
    Time - O(dist): Counting only set bits.
    Space - O(1): Auxiliary.
The time is at most 32 (or the size of int).
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        x ^= y;
        int hd = 0;
        while(x > 0) {
            x &= (x - 1);
            ++hd;
        }

        return hd;
    }
};
