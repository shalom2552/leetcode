/*
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
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // sort for early pruning
        sort(candidates.begin(), candidates.end());
        
        // vectors to  hold result and current colution
        vector<vector<int>> res;
        vector<int> curr;
        
        // recursively search solutions and build the result
        recurse(candidates, target, 0, res, curr);
        return res;
    }

    // recursively search for solutions on a decision tree
    // in each decision either include or exclude current candidate
    void recurse(vector<int> const& candidates, int target, size_t i,
                vector<vector<int>>& res, vector<int>& curr)
        {

        // no solution, skip
        if (target < 0 || i == candidates.size()) {
            return;
        }

        // found a soution
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        // search including candidate i
        curr.push_back(candidates[i]);
        recurse(candidates, target - candidates[i], i, res, curr);
        
        // search excluding candidate i (backtrack)
        curr.pop_back();
        recurse(candidates, target, i + 1, res, curr);
    }
    
};
