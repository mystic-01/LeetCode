class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp = "";
        for (auto i = 0; i < s.length(); i++) {
            ans += (s[i] == ' ') ? temp + " " : "";
            temp = (s[i] == ' ') ? "" : s[i] + temp;
        };
        return ans + temp;
    };
};