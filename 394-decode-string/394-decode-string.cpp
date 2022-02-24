class Solution {
public:
    string decodeString(string s) {
        int n = s.length(), i = 0;
        string ans = "";
        while (i < s.length()) {
            if (isdigit(s[i])) {
                string num = "", tbr = "";
                while (isdigit(s[i])) num += s[i++];
                int size = stoi(num);
                i++;
                int openBrackets = 1, closedBrackets = 0; 
                while (openBrackets != closedBrackets) {
                    if (s[i] == '[') openBrackets++;
                    else if (s[i] == ']') closedBrackets++;
                    tbr += s[i++];
                };
                
                tbr = decodeString(tbr);
                while (size--) ans += tbr;
                
            } else if (isalpha(s[i])) ans += s[i++];
            else i++;
        };
        return ans;
    };
};