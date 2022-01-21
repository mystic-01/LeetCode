class Solution {
public:
    string replaceDigits(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);       
        for (auto i = 1; i < s.length(); i++)
            if (i % 2) s[i] = (char)(s[i - 1] + s[i] - '0');
        return s;
    };
};