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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        create_sub_tree(root, nums, 0, nums.size() - 1);
        return root;
    }

private:
    // In-order traversal
    void create_sub_tree(TreeNode*& node, vector<int>& nums, int l, int r)
    {
        if (l > r)
            return;

        int mid = l + (r - l) / 2;
        node = new TreeNode(nums[mid]);
        
        create_sub_tree(node->left, nums, l, mid - 1);
        create_sub_tree(node->right, nums, mid + 1, r);
    }
};