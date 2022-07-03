class MinStack {
public:
    stack<int> s;
        stack<int> ss;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
    if(ss.empty() or x<=ss.top())
    {
        ss.push(x);
    }
    }
    
    void pop() {
        if(s.empty()) return;
        int t = s.top();
        s.pop();
        if(t == ss.top()) ss.pop();
        }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(ss.empty()) return -1;
        return ss.top();
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