/*
Motivation: DFS.
    Recursively invert left and right subtrees, then swap them.
Complexity: 
    Time - O(n): Visit each node once.
    Space - O(h): Recursion stack depth is the height of the tree.

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        // tree leaf - already inverted
        if (!root) {
            return root;
        }

        // invert left
        if (root->left) {
            invertTree(root->left);
        }

        // invert left
        if (root->right) {
            invertTree(root->right);
        }

        // swap left and right
        std::swap(root->left, root->right);
        
        return root;
    }
};
