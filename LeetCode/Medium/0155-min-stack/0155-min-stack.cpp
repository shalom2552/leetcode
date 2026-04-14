/*
Motivation: Augmented Stack.
      Use a stack of pairs, each pair holds the value and the minimum
      value at the time it was pushed. When pushing, calculate the min
      between the new value and the current min. When getting the min,
      just return the second element from the top pair.
      If the stack is empty, return INT_MAX so min(val, INT_MAX) picks val.
Complexity: 
    Time - O(1): All operations are constant time.
    Space - O(n): Storing a pair for each element.
*/

class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
        int cur_min = std::min(val, getMin());
        m_stack.push({val, cur_min});
    }
    
    void pop() {
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top().first;
    }
    
    int getMin() {
        if ( !m_stack.empty() ) {
            return m_stack.top().second;
        }
        return INT_MAX;
    }

private:
    std::stack<std::pair<int, int>> m_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */