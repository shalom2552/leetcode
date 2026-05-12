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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* invert a tree to its mirror shape */
static struct TreeNode* invertTree(struct TreeNode* root);

/* return true if both trees are the same */
static bool trees_equal(const struct TreeNode* const root1, const struct TreeNode* const root2);

bool isSymmetric(struct TreeNode* root) {

    // empty is symmetric
    if (!root) {
        return true;
    }

    // invert left sub tree
    invertTree(root->left);

    // compare both sub trees
    return trees_equal(root->left, root->right);
}

static struct TreeNode* invertTree(struct TreeNode* root) {
    
    // tree leaf - already inverted
    if (!root || (!root->left && !root->right)) {
        return root;
    }

    // invert left and right sub trees
    invertTree(root->left);
    invertTree(root->right);

    // swap left and right
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}

static bool trees_equal(const struct TreeNode* const root1, const struct TreeNode* const root2) {

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
