class Solution {
public:
    int eval(string &str) {
        int n = str.length(), ans = 0, multiplier = 1, i = 0;
        string temp = "";
        while (i < n) {
            
            if (str[i] == '-') multiplier = -1, i++;
            else if (str[i] == '+') multiplier = 1, i++;
            
            while (i < n && str[i] != '-' && str[i] != '+') temp += str[i++];
            
            if (temp != "") ans += (multiplier * stoi(temp)), temp = "";
        };
        return ans;
    };
    
    int calculate(string &s) {
        int n = s.length(), ans = 0, i = 0;      
        string temp = "";
        char sign = '+';
        
        stack<pair<int, char>> st;
        
        while (i < n) {
            
            if (s[i] == '-' || s[i] == '+') temp += s[i], sign = s[i];
            else if (s[i] == '(') st.push({eval(temp), sign}), temp = "", sign = '+';
            else if (s[i] == ')') {
                int curr = eval(temp);
                
                int num = st.top().first;
                char sign = st.top().second;
                st.pop();
                
                curr = (sign == '-') ? num - curr : num + curr;
                
                temp = to_string(curr);
            } else if (s[i] != ' ') temp += s[i];
        
            i++;
        };
        
        ans = eval(temp);
        return ans;
    };
};