class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (auto &i : tokens) {
            if (i == "/" || i == "*" || i == "+" || i == "-") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                switch (i[0]) {
                    case '/' : 
                        st.push(op1 / op2);
                        break;
                    case '*' : 
                        st.push(1L * op1 * op2);
                        break;
                    case '+' : 
                        st.push(op1 + op2);
                        break;
                    case '-' : 
                        st.push(op1 - op2);
                        break;
                };
                
            } else st.push(stoi(i));
        };
        return (int)st.top();
    };
};