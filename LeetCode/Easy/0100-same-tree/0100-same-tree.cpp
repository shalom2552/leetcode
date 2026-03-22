/**
 * Motivation: DFS.
 *     Compare the trees node by node, starting from the root.
 *     If both current nodes are null, they are identical at this position. 
 *     If only one is null, the trees differ. If both not null, check if the values are equal.
 *     Recursively check that the left subtrees and the right subtrees.
 * Complexity: 
 *     Time - O(n): We visit each node in both trees exactly once.
 *     Space - O(h): The recursion stack depth depends on the height of the tree (h).
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // one or both not exist, if both then true else false
        if ( !p || !q ) {
            return p == q;
        }

        // both exist but not equal
        if (p->val != q->val) {
            return false;
        }

        // return false if both lefts or both rights are not the same
        if ( !isSameTree(p->left, q->left) || !isSameTree(p->right, q->right) ) {
            return false;
        }

        // no conflict found
        return true;
    }
};
