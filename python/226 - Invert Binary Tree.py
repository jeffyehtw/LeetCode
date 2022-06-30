# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root:
	        self.invertLeaf(root)
        return root

    def invertLeaf(self, node):
    	temp = node.right
    	node.right = node.left
    	node.left = temp

    	if node.right:
    		self.invertLeaf(node.right)
    	if node.left:
    		self.invertLeaf(node.left)
        