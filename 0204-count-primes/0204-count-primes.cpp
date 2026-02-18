/*
Motivation: We'll initialize an array represents all the number from
    0 to n-1 with boolean type sets to True.
    Then we'll calculate all the non prime numbers using all the previous
    prime numbers from the array, by multiplying them by the current value. 
    That is all the numbers that have a devisor smaller than them are not prime.
Complexity: 
    Time - O(n*loglogn): n time p/n times for each p prime.
        Sum of reciprocals of primes grows as loglogn:
        https://en.wikipedia.org/wiki/Mertens'_theorems
    Space - O(n): bool vector for all numbers up to n
*/
class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2) {
            return 0;
        }
        
        // index representation of numbers up to n
        std::vector<bool> is_prime(n, true);

        // we can checck up until sqrt of n to save suplicates
        int sqrt_n = (int)(std::sqrt(n) + 1);
        // update is_prime with all non prime numbers
        for (long i = 2; i < sqrt_n; ++i) {
            // if i is not prime it will not find a new non prime
            if (is_prime[i]) {
                // find all numbers that are divisble by i
                for (long j = i * i; j < n; j += i) {
                    // j is a multiple of smaller number diffrent than 1
                    is_prime[j] = false;
                }
            }
        }

        // count all primes from 1 to n-1
        int count = 0;
        for (int num = 2; num < n; ++num) {
            if (is_prime[num]) {
                ++count;
            }
        }

        return count;
    }
};
