class MyQueue {

private:
    stack<int> s;

public:
    MyQueue() {
        
    };
    
    void push(int x) {
        s.push(x);
    };
    
    int pop() {
        int x = s.top();
        s.pop();
        
        if (s.empty()) return x;
        
        int ans = pop();
        s.push(x);
        return ans;
    };
    
    int peek() {
        int x = s.top();
        s.pop();
        
        if (s.empty()) {
            s.push(x);
            return x;
        };
        
        int ans = peek();
        s.push(x);
        return ans;
    };
    
    bool empty() {
        return !s.size();        
    };
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */