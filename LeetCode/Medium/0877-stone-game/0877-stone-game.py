"""
Motivation: Win is guaranteed.
    Since odd and even piles are must be the same size, 
    they cannot be equal by sum since the total sum would be even (must be odd).
    Since Alice can choose either to pick only odd or even piles,
    she can choose the group with the max stones, and always win.
    If she picks even, then on each Bob turn he has only odd indices
    to choose from, and vice versa. Alice always win.
Coomplexity:
    Time - O(1)
    Space - O(1)
"""
class Solution:

    def stoneGame(self, piles: List[int]) -> bool:
        return True
    
    def stoneGameBroutForce(self, piles: List[int]) -> bool:
        # total = sum(piles)
        # length = len(piles)

        # # recursively try to take left or right pile
        # def check(a_score, b_score, idx):
        #     if idx == 1 + length // 2 : # idx passed mid
        #         return a_score > b_score

        #     # early return - has more than half
        #     if a_score > total // 2:
        #         return True

        #     left, right = idx, length - idx - 1
        #     take_left = check(a_score + piles[left], b_score + piles[right], idx + 1)
        #     take_right = check(a_score + piles[right], b_score + piles[left], idx + 1)

        #     return take_left or take_right # won on either play
            
        # return check(0, 0, 0)
        pass
