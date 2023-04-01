class Solution {
public:
   int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n = tokens.size();
        
        for (auto i = n - 1; i >= 0; i--) {
            if (st.size() && 
                isdigit(tokens[i][tokens[i].size() - 1]) && isdigit(st.top()[st.top().size() - 1])) {
                st.push(tokens[i]);                
                while (true) {
                    int num1 = stoi(st.top());
                    st.pop();
                    int num2 = stoi(st.top());
                    st.pop();
                    char character = st.top()[0];
                    st.pop();
                        
                    if (character == '+') num1 += num2;
                    else if (character == '-') num1 -= num2;
                    else if (character == '*') num1 *= num2;
                    else if (character == '/') num1 /= num2;
                    if (st.size()) character = st.top()[st.top().size() - 1];
        
                    st.push(to_string(num1));
                    if (st.size() <= 2 || !isdigit(character)) break;
                };
            } else st.push(tokens[i]);
        };
        
        return stoi(st.top());
    };
};