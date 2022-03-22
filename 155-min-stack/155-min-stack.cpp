class MinStack {
public:
    stack<int> st, stm;
    MinStack() {
        st = stack<int>();
        stm = stack<int>();
    }
    
    void push(int val) {
        st.push(val);
        if(stm.empty() || val <= getMin()) {
            stm.push(val);
        }
    }
    
    void pop() {
        if(st.top() == getMin()) {
            stm.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stm.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */