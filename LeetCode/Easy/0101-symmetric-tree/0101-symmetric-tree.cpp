/**
 * Motivation: DFS.
 *     Invert the left subtree and compare it with the right subtree.
 *     If both are equal, the tree is symmetric.
 * Complexity: 
 *     Time - O(n): Visit each node once for inverting and comparing.
 *     Space - O(h): Recursion stack depth is the height of the tree.
 *
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
    bool isSymmetric(TreeNode* root) {

        // empty is symmetric
        if (!root) {
            return true;
        }

        // invert left sub tree
        invertTree(root->left);

        // compare both sub trees
        return trees_equal(root->left, root->right);
    }

private:
    static TreeNode* invertTree(TreeNode* root) {
        
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

    static bool trees_equal(const TreeNode* const root1, const TreeNode* const root2) {

        // both leafs
        if (!root1 && !root2) {
            return true;
        }

        // only one is nullptr
        if (!root1 != !root2) {
            return false;
        }

        // values not equal
        if (root1->val != root2->val) {
            return false;
        }

        // check left and right subtrees
        if (!trees_equal(root1->left, root2->left)) {
            return false;
        }
        return trees_equal(root1->right, root2->right);
    }
};
