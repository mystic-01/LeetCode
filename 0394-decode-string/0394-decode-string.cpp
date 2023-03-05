class Solution {
public:
    string decodeString(string s) {
        int n = s.length(), i = 0;
        string ans = "";
        while (i < n) {
            if (isdigit(s[i])) {
                string num = "", tbr = "";
                while (i < n && isdigit(s[i])) num += s[i++];
                int size = stoi(num);
                i++;
                int openBrackets = 1, closedBrackets = 0; 
                while (i < n && openBrackets != closedBrackets) {
                    if (s[i] == '[') openBrackets++;
                    else if (s[i] == ']') closedBrackets++;
                    tbr += s[i++];
                };
                
                tbr = decodeString(tbr);
                while (size--) ans += tbr;
                
            } else if (i < n && isalpha(s[i])) ans += s[i++];
            else i++;
        };
        return ans;
    };
};