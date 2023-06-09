class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int idx = 0, target = s.length();
        
        for (auto &str : words) {
            for (auto &ch : str) {
                if (ch == s[idx]) idx++;
                else return false;
            };
            if (idx == target) return true;
        };
        
        return (idx == target);
    };
};