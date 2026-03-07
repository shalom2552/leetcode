/* 
Motivation: In-order traversal on the tree and check for violation on the fly.
Complexity:
    Time - O(n): In-order traversal.
    Space - O(1): No extra space.
Recursion used for traversal.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = -2147483649LL;
        return in_order(root, prev);
    }

private:
    bool in_order(TreeNode* node, long long& prev) // 2, 1
    {
        // node is a leaf, no violation
        if (node == nullptr) {
            return true;
        }
        
        // travers left
        if (not in_order(node->left, prev)) {
            return false;
        }

        // check for violation
        if (prev >= node->val) {
            return false;
        }
        
        // update prev and traverse left
        prev = node->val;
        return in_order(node->right, prev);
    }

};
