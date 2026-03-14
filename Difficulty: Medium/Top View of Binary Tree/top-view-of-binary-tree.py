'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def topView(self, root):
        # code here
        from collections import deque
        left, right = [], []
        s = deque([(root, 0)])
        while s:
            node, i = s.popleft()
            if node is None:
                continue
            if i < 0:
                if -i > len(left):
                    left.append(node.data)
            else:
                if i == len(right):
                    right.append(node.data)
            s.append((node.left, i - 1))
            s.append((node.right, i + 1))
        left.reverse()
        left.extend(right)
        return left
        
        