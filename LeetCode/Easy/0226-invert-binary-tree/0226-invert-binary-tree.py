# Motivation: DFS.
#     Recursively invert left and right subtrees, then swap them.
# Complexity: 
#     Time - O(n): Visit each node once.
#     Space - O(h): Recursion stack depth is the height of the tree.
# 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
       # tree leaf - already inverted
        if not root or (not root.left and not root.right):
            return root

        # invert left and right sub trees
        self.invertTree(root.left)
        self.invertTree(root.right)

        # swap left and right
        root.left, root.right = root.right, root.left

        return root
