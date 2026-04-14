"""
Motivation: Frequency Stacks.
      Use a hashmap to count each element's frequency and a hashmap of
      stacks where each key is a frequency level and the value is a stack
      of elements pushed at that frequency. Keep track of the max frequency.
      When pushing, increment the element's frequency and push it to the
      corresponding frequency stack. When poping, pop from the max frequency
      stack and decrement the element's frequency. If the max frequency stack
      becomes empty, decrement max frequency.
Complexity: 
    Time - O(1): All operations are constant time.
    Space - O(n): Storing each element in the frequency map and stacks.
"""
class FreqStack:

    def __init__(self):
        self.m_freq = 0
        self.m_freq_map = defaultdict(int)
        self.m_stack = defaultdict(list)
        
    def push(self, val: int) -> None:
        # get val's freq - map default value is 0
        self.m_freq_map[val] += 1
        val_freq = self.m_freq_map[val]

        # push to the right freq stack
        self.m_stack[val_freq].append(val)

        # update stack's max freq
        self.m_freq = max(self.m_freq, val_freq)
    
    def pop(self) -> int:
        # extract top value
        top_val = self.m_stack[self.m_freq].pop()
        self.m_freq_map[top_val] -= 1

        # update stack's max freq
        if (len(self.m_stack[self.m_freq]) == 0):
            self.m_freq -= 1

        return top_val
    
