class Solution {
public:
    string reverseParentheses(string &s) {
        int n = s.length();
        string ans = "";
        stack<int> st;
        
        for (auto i = 0; i < n; i++) {
            if (s[i] ==  '(') st.push(i + 1);
            else if (s[i] ==  ')') {
                reverse(s.begin() + st.top(), s.begin() + i);
                st.pop();
            };
        };
        
        for (auto &i : s) if (i != '(' && i != ')') ans += i;
        return ans;
    };
};

