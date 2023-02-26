class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int len = 0, mod = 0;
        
        for (auto &i : s) m[i]++;
        for (auto &it : m) mod = max(mod, it.second % 2), len += (it.second - (it.second % 2));        

        return len + mod;
    };
};