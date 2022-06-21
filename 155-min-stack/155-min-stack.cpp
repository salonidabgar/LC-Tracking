class MinStack {
private:
    stack<pair<int,int>> st;
    int minn = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) minn = val;
        else
        {
            minn = min(st.top().second, val);
        }
        st.push({val, minn});
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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