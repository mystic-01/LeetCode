class Solution {
public:
    string lastNonEmptyString(string s) {
        int freq[26] = {0}, maxFreq = 0;
        unordered_set<char> charSet;
        string ans = "";
        for (char &ch : s) {
            if (++freq[ch - 'a'] > maxFreq) {
                maxFreq = freq[ch - 'a'];
                charSet = unordered_set<char>();
            };    
            if (freq[ch - 'a'] == maxFreq) {
                charSet.insert(ch);    
            };
        };
        for (int i = s.size() - 1; i >= 0; --i) {
            if (charSet.count(s[i])) {
                ans = s[i] + ans;
                charSet.erase(s[i]);
            };    
        };
        return ans;
    };
};