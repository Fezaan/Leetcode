class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        int minEle= s.empty() ? val: min(val,s.top().second);
        s.push({val,minEle});
    }
    
    void pop() {
        if(s.empty())   return;
        int t=s.top().first;
        s.pop();
    }
    
    int top() {
        return s.empty() ? -1 : s.top().first;
    }
    
    int getMin() {
        return s.empty() ? -1: s.top().second;
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