class Solution {
public:
    bool isPalindrome(int x) {
        // negative number is not a polindrome
        if (x < 0) {
            return false;
        }

        long reversed = 0;
        int xcopy = x;
        
        // reverse x 
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
           x = x / 10; 
        }

        return xcopy == reversed;
    }
};