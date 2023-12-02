class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0, baseFreq[26] = {0}, dupeFreq[26] = {0};
        for (char &ch : chars) {
            ++baseFreq[ch - 'a'];    
        };
        for (string &str : words) {
            for (int i = 0; i < 26; ++i) {
                dupeFreq[i] = baseFreq[i];
            };
            bool canbeFormed = true;
            for (char &c : str) {
                if (--dupeFreq[c - 'a'] < 0) {
                    canbeFormed = false;    
                };
            };
            if (canbeFormed) {
                ans += str.size();    
            };
        };        
        
        return ans;
    };
};