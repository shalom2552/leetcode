# Motivation: Backtracking.
#     Iteratively traverse the tree from root to leaf,
#     subtracting the current node's value from the target sum at each step.
#     A valid path is found if we reach a leaf node where the remaining target 
#     sum equals the node's value.
# Complexity:
#     Time - O(n): Visit each node in the tree at most once.
#     Space - O(n): Store in Stack every node we visit.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        # stack to hold nodes to visit
        stack = []
        stack.append([root, targetSum])

        # iteratively traverse the tree from root to leaf
        while stack:
            node, target = stack.pop()

            # empty node
            if not node:
                continue

            # found path: node is leaf and the value sums up to target
            if not node.left and not node.right and target - node.val == 0:
                return True
            
            # add left and right to stack to visit
            stack.append([node.left, target - node.val])
            stack.append([node.right, target - node.val])

        return False
