/*
* Motivation: Math / Combinatorics.
*     Loop over the number lengths from 0 to n.
*     For each length, calculate how many unique digit numbers we can make.
*     The first digit has 9 choices (can't be 0), the second has 9 choices, the third has 8, and so on.
*     Multiply these choices together in the inner loop and add them to the total sum.
* Complexity: 
*     Time - O(n): Looping up to n times (and n can be at most 10 before we run out of unique digits).
*     Space - O(1): We only save the total and sub_total variables.
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        // total count of numbers with unique digits
        int total = 0;

        // for every digit-length numbers
        for (int i = 0; i <= n; ++i) {
            // set to 1 to multiply
            int sub_total = 1;   
            // for every number option
            for (int j = 10; j > 10 - i; --j) {
                // calculate total combanitions, most left digit can't be 0
                sub_total *= j < 10 ? j : j - 1;
            }
            total += sub_total;
        }
        return total;
    }
};
