class MinStack {
   public:
    MinStack() {}

    std::stack<std::pair<int, int>> m_stack;

    void push(int val) {
        if (m_stack.empty()) {
            m_stack.push({val, val});
        } else {
            std::pair<int, int> top = m_stack.top();
            m_stack.push({val, std::min(top.second, val)});
        }
    }

    void pop() { m_stack.pop(); }

    int top() { return m_stack.top().first; }

    int getMin() { return m_stack.top().second; }
};