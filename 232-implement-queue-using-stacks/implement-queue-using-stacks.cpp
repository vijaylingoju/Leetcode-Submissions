class MyQueue {
public:
    stack<int>s,cps;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.empty())s.push(x);
        else{
            while(!s.empty()){
                cps.push(s.top());
                s.pop();
            }
            cps.push(x);
            while(!cps.empty()){
                s.push(cps.top());
                cps.pop();
            }
        }
    }
    
    int pop() {
        int k = s.top();
        s.pop();
        return k;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */