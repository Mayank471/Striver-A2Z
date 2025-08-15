class MinStack {
public:
    stack<long long> s;
    long long min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            min = val;
            s.push(val);
        }
        else {
            if(val<min) {
                s.push((long long)2*val-min);
                min=val;
            }
            else s.push(val);
        }
    }
    
    void pop() {
        if(s.empty())return;
        if(s.top()<min){
            min = 2*min-s.top();
            s.pop();
            return;
        }
        else {
            s.pop();
            return;
        }
    }
    
    int top() {
        if(s.empty())return -1;
        if(s.top()<min){
            return min;
        }
        else return s.top();
    }
    
    int getMin() {
        return min;
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