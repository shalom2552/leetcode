/**
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
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};