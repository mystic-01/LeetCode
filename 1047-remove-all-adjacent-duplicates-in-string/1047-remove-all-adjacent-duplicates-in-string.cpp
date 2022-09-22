class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.length()) {
            if (!st.empty() && s[i] == st.top()) {
                st.pop();
                s.erase(s.begin() + i - 1, s.begin() + i + 1);
                i--;
            } else st.push(s[i]), i++;  
        }; 
        return s;
    };
};