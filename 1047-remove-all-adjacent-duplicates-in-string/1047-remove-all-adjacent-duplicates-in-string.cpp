class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto &x : s) 
            if (!st.empty() && x == st.top()) st.pop();
            else st.push(x);
        
        s = "";
        while (!st.empty()) {
            s = st.top() + s;
            st.pop();
        };
        return s;
    };
};