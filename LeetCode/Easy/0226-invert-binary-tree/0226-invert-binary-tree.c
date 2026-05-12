/*
Motivation: DFS.
    Recursively invert left and right subtrees, then swap them.
Complexity: 
    Time - O(n): Visit each node once.
    Space - O(h): Recursion stack depth is the height of the tree.
 */
struct TreeNode* invertTree(struct TreeNode* root) {

    // tree leaf - already inverted
    if (!root || (!root->left && !root->right)) {
        return root;
    }

    // invert left and right sub trees
    invertTree(root->left);
    invertTree(root->right);

    // swap left and right
    struct TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;

    return root;
}
