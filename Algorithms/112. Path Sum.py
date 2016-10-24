# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        return self.pathSum(root, sum, 0)
        
    def pathSum(self, node, target, cur):
        if not node.left and not node.right:
            return cur + node.val == target
        
        left = False
        right = False
        cur += node.val
        
        if node.left:
            left = self.pathSum(node.left, target, cur)
        if node.right:
            right = self.pathSum(node.right, target, cur)
            
        return left or right    
    