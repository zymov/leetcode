class Node:
    def __init__(self, val, curMin):
        self.val = val
        self.curMin = curMin
        self.next = None

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.topP = None
        self._min = None

    def push(self, x: int) -> None:
        if self._min == None or self._min > x:
            self._min = x
        n = Node(x, self._min)
        if self.topP:
            n.next = self.topP
        self.topP = n

    def pop(self) -> None:
        if not self.topP:
            return
        tmp = self.topP
        self.topP = self.topP.next
        if self.topP:
            self._min = self.topP.curMin
        else:
            self._min = None

    def top(self) -> int:
        return self.topP.val

    def getMin(self) -> int:
        return self.topP.curMin


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
