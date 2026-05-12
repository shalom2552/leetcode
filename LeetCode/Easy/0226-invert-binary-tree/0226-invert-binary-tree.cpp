/*
Motivation: DFS.
    Recursively invert left and right subtrees, then swap them.
Complexity: 
    Time - O(n): Visit each node once.
    Space - O(h): Recursion stack depth is the height of the tree.
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
       // tree leaf - already inverted
        if (!root || (!root->left && !root->right)) {
            return root;
        }

        // invert left and right sub trees
        invertTree(root->left);
        invertTree(root->right);

        // swap left and right
        std::swap(root->left, root->right);

        return root;
    }
};
