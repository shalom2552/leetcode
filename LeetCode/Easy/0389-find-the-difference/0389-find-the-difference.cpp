/*
Motivation: Bitwise on char values.
    Sum all the elements of t and substract the sum of s.
    We'll left with the char value of the extra char and we can return it.
Complexity:
    Time - O(s+t): Summing the strings.
    Space - O(1): Auxiliary.

*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = accumulate(t.begin(), t.end(), 0);
        return sum - accumulate(s.begin(), s.end(), 0);
    }
};