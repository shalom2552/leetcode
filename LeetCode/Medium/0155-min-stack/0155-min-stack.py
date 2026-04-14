"""
Motivation: Augmented Stack.
      Use a stack of pairs, each pair holds the value and the minimum
      value at the time it was pushed. When pushing, calculate the min
      between the new value and the current min. When getting the min,
      just return the second element from the top pair.
      If the stack is empty, return INT_MAX so min(val, INT_MAX) picks val.
Complexity: 
    Time - O(1): All operations are constant time.
    Space - O(n): Storing a pair for each element.
"""
class MinStack:

    def __init__(self):
        self.m_stack = []
        
    def push(self, val: int) -> None:
        cur_min = min(val, self.getMin())
        self.m_stack.append([val, cur_min])

    def pop(self) -> None:
        self.m_stack.pop()

    def top(self) -> int:
        return self.m_stack[-1][0]

    def getMin(self) -> int:
        if len(self.m_stack) == 0:
            return float('inf')
        return self.m_stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()