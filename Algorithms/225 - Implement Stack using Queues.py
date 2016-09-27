class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.data.append(x)
        

    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.data) > 0:
            self.data.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.data[len(self.data) - 1]
        

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.data) == 0
        