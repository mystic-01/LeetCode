class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans = "";
        for (auto &i : s) {
            if (i == '(') st.push(i);
            else if (i == ')') {
                if (st.empty()) continue;
                st.pop(); 
            }; 
            ans += i;
        };
        int wrongParentheses = st.size();
        while (wrongParentheses--) {
          ans.erase(ans.find_last_of('('), 1);  
        };
        return ans;
    };
};