# Motivation: DFS.
#     Invert the left subtree and compare it with the right subtree.
#     If both are equal, the tree is symmetric.
# Complexity: 
#     Time - O(n): Visit each node once for inverting and comparing.
#     Space - O(h): Recursion stack depth is the height of the tree.
# 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # empty is symmetric
        if not root:
            return true

        # invert left sub tree
        self.invertTree(root.left)

        # compare both sub trees
        return self.trees_equal(root.left, root.right)
        
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """ invert a tree to its mirror shape """
        
       # tree leaf - already inverted
        if not root or (not root.left and not root.right):
            return root

        # invert left and right sub trees
        self.invertTree(root.left)
        self.invertTree(root.right)

        # swap left and right
        root.left, root.right = root.right, root.left

        return root

    def trees_equal(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        """ return true if both trees are the same """

        # both leafs
        if not root1 and not root2:
            return True

        # only one is nullptr
        if (not root1) != (not root2):
            return False

        # values not equal
        if root1.val != root2.val:
            return False

        # check left and right subtrees
        if not self.trees_equal(root1.left, root2.left):
            return False
        return self.trees_equal(root1.right, root2.right)
