class Solution {
public:
    string build(string s) {
        int c = 0, n = s.length();
        for (auto i = 0; i < n; i++) {
            if (s[i] == '#') c = max(0, --c);
            else s[c++] = s[i];
        };
        return s.substr(0, c);
    };
    
    bool backspaceCompare(string s, string t) {
//         stack<char> st1, st2;
//         for (auto &i : s) 
//             if (i != '#') st1.push(i);
//             else if (!st1.empty()) st1.pop();
        
//         for (auto &j : t) 
//             if (j != '#') st2.push(j);
//             else if (!st2.empty()) st2.pop();
        
//         while (!st1.empty() && !st2.empty()) {
//             if (st1.top() != st2.top()) return false;
//             st1.pop(), st2.pop();
//         };
//         return st1.size() == st2.size();
        return build(s) == build(t);
    };
};
