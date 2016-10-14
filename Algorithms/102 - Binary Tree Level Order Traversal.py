# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # init
        level = []
        stack = [root]
        
        while len(stack):
            # new 
            _stack = []
            _level = []
            
            while len(stack):
                cur = stack.pop(0)
                
                if cur == None:
                    continue
                
                if cur.left:
                    _stack.append(cur.left)
                if cur.right:
                    _stack.append(cur.right)
                _level.append(cur.val)
                
            # cp
            for i in _stack:
                stack.append(i)

            if _level != []:
                level.append(_level)
            
        return level    