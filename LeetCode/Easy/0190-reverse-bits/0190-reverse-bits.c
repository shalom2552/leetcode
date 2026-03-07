/*
Motivation: Bit manipulation.
      Loop 32 times (for every bit in an int).
      In each iteration, we shift our result to the left to make room.
      Take the last bit of n using & 1 and put it in res using |.
      Then shift n to the right to get the next bit.
Complexity: 
    Time - O(1): We always loop exactly 32 times.
    Space - O(1): Only saving the res variable.
*/
int reverseBits(int n) {
    int res = 0;

    for (int i = 0; i < 32; i++){
        // make room for the next bit
        res = res << 1;
        // get the last bit of n and add to res
        res = res | (n & 1);
        // move to the next bit in n
        n = n >> 1;
    }

    return res;    
}