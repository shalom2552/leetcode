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