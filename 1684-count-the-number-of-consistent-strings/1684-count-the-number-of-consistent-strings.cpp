class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s(begin(allowed), end(allowed));
        int ans = 0;
        for (auto &str : words) {
            bool isConsistent = true;
            for (char &ch : str) {
                if (s.find(ch) == s.end()) {
                    isConsistent = false;
                    break;
                };
            };            
            ans += isConsistent;
        };
        return ans;
    };
};