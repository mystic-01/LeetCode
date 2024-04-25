class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, swaps = 0, n = s.size(), swapsRev = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == ']') {
                ++close;
            } else {
                ++open;    
            };         
            if (close > open) {
                ++swaps, --close, ++open;    
            };
        };
        reverse(begin(s), end(s));
        open = 0, close = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '[') {
                ++close;
            } else {
                ++open;    
            };         
            if (close > open) {
                ++swapsRev, --close, ++open;    
            };
        };        
        return max(swaps, swapsRev);
    };
};