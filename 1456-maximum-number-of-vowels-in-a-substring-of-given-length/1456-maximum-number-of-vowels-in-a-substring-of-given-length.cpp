class Solution {
public:
    bool isVowel (char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';        
    };
    
    int maxVowels(string s, int k) {
        int n = s.length(), lo = 0, count = 0, best = 0;  
        for (auto i = 0; i < n; i++) {
            count += isVowel(s[i]) ? 1 : 0;
            if (i >= k) count -= isVowel(s[lo++]) ? 1 : 0;
            if (i >= k - 1) best = max(best, count);                        
        };
        return best;
    };
};