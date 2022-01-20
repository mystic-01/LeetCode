class Solution {
public:
    string reverseWords(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        string ans = "", temp = "";
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                ans += temp + " ";
                temp = "";
            } else temp = s[i] + temp;
        };
        return ans + temp;
    };
};