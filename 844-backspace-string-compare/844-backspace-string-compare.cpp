class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for (auto &i : s) 
            if (i != '#') st1.push(i);
            else if (!st1.empty()) st1.pop();
        
        for (auto &j : t) 
            if (j != '#') st2.push(j);
            else if (!st2.empty()) st2.pop();
        
        while (!st1.empty() && !st2.empty()) {
            if (st1.top() != st2.top()) return false;
            st1.pop(), st2.pop();
        };
        return st1.size() == st2.size();
    };
};