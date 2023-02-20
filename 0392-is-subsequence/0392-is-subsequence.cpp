class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (auto i = 0; i < t.size(); i++) index += t[i] == s[index];
        return index == s.size();
    };
};