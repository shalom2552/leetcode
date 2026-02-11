class Solution(object):
    def isPalindrome(self, x):
        x = str(x)
        if len(x) < 2:
            return True
        
        i = 0
        j = len(x) - 1

        # check the digits from edges to mid
        while i < j:
            if x[i] != x[j]:
                return False
            i += 1
            j -= 1

        return True
        