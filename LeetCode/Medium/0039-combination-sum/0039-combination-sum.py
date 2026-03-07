"""
Motivation: Backtracking.
    Sort the array first for early pruning.
    Use a recursive function and in each step we have 2 choices:
    1. Take the current number (and we can take it again, so stay in i).
    2. Don't take the current number and move to the next one (i + 1).
    If target becomes 0 we found a solution.
Complexity: 
    Time - O(2^t): Exponential because of the recursive choices.
    Space - O(t): The depth of the recursion tree.
Where t is the target value (worst-case can have a candidate with a value = 1).
"""
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # sort for early pruning
        candidates.sort()
        
        # lists to hold result and current colution
        res, curr = [], []
        
        # in each decision either include or exclude current candidate
        def dfs(target: int, i: int):
            # no solution, skip
            if target < 0 or i == len(candidates):
                return

            # found a soution
            if target == 0:
                # append a copy of curr
                res.append(curr[:])
                return

            # search including candidate i
            curr.append(candidates[i])
            dfs(target - candidates[i], i)
            
            # search excluding candidate i (backtrack)
            curr.pop()
            dfs(target, i + 1)
            
        # recursively search solutions and build the result
        dfs(target, 0)
        return res
