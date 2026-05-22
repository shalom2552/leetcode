# Motivation: In-order traversal (DFS).
#     Traverse the tree in-order (left, root, right) and
#     write each node's value to the array.
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
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.traverse(root, result)
        return result
        

    def traverse(self, root: Optional[TreeNode], res: List[int]):
        if not root:
            return
        # traverse: left -> read -> right
        self.traverse(root.left, res)
        res.append(root.val)
        self.traverse(root.right, res)
