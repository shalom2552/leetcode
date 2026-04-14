class FreqStack {
public:
    FreqStack()
    {
    }
    
    void push(int val) {
        // get val's freq - map default value is 0
        size_t val_freq = ++m_freq_map[val];

        // push to the right freq stack
        m_stack[val_freq].push(val);

        // update stack's max freq
        m_freq = std::max(m_freq, val_freq);
    }
    
    int pop() {
        // extract top value
        int top_val = m_stack[m_freq].top();
        m_stack[m_freq].pop();
        --m_freq_map[top_val];

        // update stack's max freq
        if (m_stack[m_freq].empty()) {
            --m_freq;
        }
        return top_val;
    }

private:
    size_t m_freq = 0;
    std::unordered_map<int, size_t> m_freq_map;
    std::unordered_map<int, std::stack<int>> m_stack;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
