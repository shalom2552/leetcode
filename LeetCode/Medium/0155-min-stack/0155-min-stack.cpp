class MinStack {
public:
    MinStack() {
        
    }
    
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