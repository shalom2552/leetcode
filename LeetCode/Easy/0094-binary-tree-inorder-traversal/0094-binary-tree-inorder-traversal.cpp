/**
 * Motivation: In-order traversal (DFS).
 *     Traverse the tree in-order (left, root, right) and
 *     write each node's value to the array.
 * Complexity: 
 *     Time - O(n): Visit each node once.
 *     Space - O(h): Recursion stack depth is the height of the tree.
 *
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
private:
    static void traverse(TreeNode const* root, vector<int>& res) {
        if (!root) {
            return;
        }
        // traverse: left -> read -> right
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
};
