class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (auto &x : str) {
            switch (x) {
                case '(': s.push(x); break;
                case '{': s.push(x); break;
                case '[': s.push(x); break;
                case ')': if (s.empty() || s.top() != '(') return false; else s.pop(); break;
                case '}': if (s.empty() || s.top() != '{') return false; else s.pop(); break;
                case ']': if (s.empty() || s.top() != '[') return false; else s.pop(); break;
            };    
        };
        return s.empty();
    };
};