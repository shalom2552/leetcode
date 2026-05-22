/*
Motivation: In-order traversal (DFS).
      Count the nodes first to allocate the result array.
      Then traverse the tree in-order (left, root, right) and
      write each node's value to the array.
Complexity: 
    Time - O(n): Visit each node twice, once for counting and once for traversal.
    Space - O(h): Recursion stack depth is the height of the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* count the number of nodes in the tree */
static int countNodes(struct TreeNode* root);

/* in order traverse the tree */
static void traverse(struct TreeNode* root, int* res, int* idx);

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(sizeof(int) * countNodes(root));
    int result_idx = 0;

    traverse(root, result, &result_idx);
    *returnSize = result_idx;

    return result;
}

static int countNodes(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

static void traverse(struct TreeNode* root, int* res, int* idx) {
    if (!root) {
        return;
    }

    // traverse: left -> read -> right
    traverse(root->left, res, idx);
    res[(*idx)++] = root->val;
    traverse(root->right, res, idx);
}
