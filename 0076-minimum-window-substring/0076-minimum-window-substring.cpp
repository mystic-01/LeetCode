class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), freq[58] = {0}, needed = t.size(), start = 0, end = INT_MAX;
        bool chars[58] = {0};
        
        for (int i = 0; i < needed; ++i) {
            chars[t[i] - 'A'] = 1, ++freq[t[i] - 'A'];    
        };
        
        for (int left = 0, i = 0; i < n; ++i) {
            if (chars[s[i] - 'A']) {
                if (freq[s[i] - 'A']-- > 0) --needed;
            };    
            while (needed == 0) {
                if (end - start > i - left) {
                    start = left, end = i;    
                };
                if (chars[s[left] - 'A']) {
                    if (freq[s[left] - 'A']++ >= 0) ++needed;                        
                };
                ++left;
            };
        };
        return end == INT_MAX ? "" : s.substr(start, end - start + 1);
    };
};