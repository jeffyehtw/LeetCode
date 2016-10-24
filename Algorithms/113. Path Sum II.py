# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.ansArr = []
        
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root:
            return []
            
        self.traversal(root, sum, [])
        
        return list(self.ansArr)
        
    def traversal(self, node, sum, path):
        if not node.left and not node.right:
            path.append(node.val)
            if math.fsum(path) == sum:
                self.ansArr.append(path)
            return
        
        if node.left:
            self.traversal(node.left, sum, path + [node.val])
        if node.right:
            self.traversal(node.right, sum, path + [node.val])
        