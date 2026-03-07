class Solution {
public:
    double myPow(double x, int n) {
        
        // 1 is valid also for n = 0
        double res = 1;
        // using long long to avoid overflow
        long long ln = n;

        // if n is negative we will reverse the problem
        // by multiply 1/x -n times, insted of x
        if (n < 0) {
            ln = -ln;
            x = 1 / x;
        }

        // multiply n times
        while (ln > 0) {
            // if n is odd multiply one time
            if (ln & 1) {
                res *= x;
            }
            // multiply n/2 times more and devide n by 2
            x *= x;
            ln >>= 1;
        }

        return res;
    }
};
