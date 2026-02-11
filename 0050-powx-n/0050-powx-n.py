class Solution:
    def myPow(self, x: float, n: int) -> float:

        res = 1

        if n < 0:
            n = -n
            x = 1 / x

        while n > 0:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        
        return res

        