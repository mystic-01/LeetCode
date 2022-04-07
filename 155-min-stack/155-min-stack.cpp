class MinStack {
private:
    stack<long long> s;
    long long mini = LLONG_MAX;
public:
    MinStack() {
    };
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                s.push(2LL * val - mini);
                mini = val;
            } else {
                s.push(val);
            };    
        };
    };
    
    void pop() {
        long long top = s.top();
        if (top < mini) mini = 2LL * mini - top; 
        s.pop();
    };
    
    int top() {
        return (s.top() < mini) ? mini : s.top();
    };
    
    int getMin() {
        return mini;    
    };
};