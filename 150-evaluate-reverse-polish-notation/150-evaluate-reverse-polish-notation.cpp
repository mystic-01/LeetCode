class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long> st;
        for (auto i = 0; i < n; i++) {
            if (tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                if (tokens[i] == "/") st.push(op1 / op2);
                else if (tokens[i] == "*") st.push(1L * op1 * op2);
                else if (tokens[i] == "+") st.push(op1 + op2);
                else if (tokens[i] == "-") st.push(op1 - op2);
            } else st.push(stoi(tokens[i]));
        };
        return (int)st.top();
    };
};