class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int chars[26] = {0}, deficiency = 0;
            for (int j = i; j < n; ++j) {
                ++chars[s[j] - 'a'];
                if (chars[s[j] - 'a'] == k && k != 1) {
                    --deficiency;
                } else if (chars[s[j] - 'a'] < k && chars[s[j] - 'a'] == 1) {
                    ++deficiency;    
                };    
                if (deficiency == 0) maxLen = max(maxLen, j - i + 1);
            };                                                
        };
        return maxLen; 
    };
};