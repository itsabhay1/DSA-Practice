class MinStack {
public:
    stack<long long>st;
    long long currMin = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            currMin = val;
            st.push(val);
        }
        else{
            if(val>currMin) st.push(val);
            else{
                st.push(2LL*val-currMin);
                currMin = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x<currMin){
            currMin = 2*currMin - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(x<currMin) return currMin;
        else return x;
    }
    
    int getMin() {
        if (st.empty()) return -1;
        return currMin;
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