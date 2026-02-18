# Motivation: We'll initialize an array represents all the number from
#     0 to n-1 with boolean type sets to True.
#     Then we'll calculate all the non prime numbers using all the previous
#     prime numbers from the array, by multiplying them by the current value. 
#     That is all the numbers that have a devisor smaller than them are not prime.
# Complexity: 
#     Time - O(n*loglogn): n time p/n times for each p prime.
#         Sum of reciprocals of primes grows as loglogn:
#         https://en.wikipedia.org/wiki/Mertens'_theorems
#     Space - O(n): bool vector for all numbers up to n

class Solution:
    def countPrimes(self, n: int) -> int:
        
        # index representation of numbers up to n
        is_prime = [True] * n

        # update is_prime with all non prime numbers
        for i in range(2, ceil(n ** 0.5)):
            # if i is not prime it will not find a new non prime
            if is_prime[i]:
                # set to false all numbers that are divisble by i 
                is_prime[i * i: n: i] = [False] * len(range(i * i, n, i))
                
        # sum all primes from 2 to n-1
        return sum(is_prime[2:n])
