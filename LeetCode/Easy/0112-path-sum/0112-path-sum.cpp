/*
Motivation: Backtracking.
    Recursively traverse the tree from root to leaf,
    subtracting the current node's value from the target sum at each step.
    A valid path is found if we reach a leaf node where the remaining target 
    sum equals the node's value.
Complexity:
    Time - O(n): Visit each node in the tree at most once.
    Space - O(h): The recursion stack depth is determined by the height of the tree (h).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        // empty node
        if ( !root ) {
            return false;
        }

        // found path: node is leaf and the value adds up to the target sum
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }

        // backtrack left and right
        if( hasPathSum(root->left, targetSum - root->val) || 
            hasPathSum(root->right, targetSum - root->val) ) {
            
            return true;
        }
        
        return false;
    }
};