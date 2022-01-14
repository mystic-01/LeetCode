class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0, index = -1;
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == ' ') count++;
            if (count == k) {
                index = i - 1;
                break;
            };
        };    
        if (index == -1 || index == s.length()) return s;
        return s.substr(0, index+1);
    };
};