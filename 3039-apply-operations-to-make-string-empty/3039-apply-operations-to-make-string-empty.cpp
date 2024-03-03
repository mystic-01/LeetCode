class Solution {
public:
    string lastNonEmptyString(string s) {
        int freq[26] = {0}, maxFreq = 0;
        unordered_set<char> charSet;
        string ans = "";
        for (char &ch : s) {
            if (++freq[ch - 'a'] > maxFreq) {
                maxFreq = freq[ch - 'a'];
            };    
        };
        for (int i = s.size() - 1; i >= 0; --i) {
            if (freq[s[i] - 'a'] == maxFreq) {
                ans = s[i] + ans;
                freq[s[i] - 'a'] = 0;
            };    
        };
        return ans;
    };
};