class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), left = 0, maxFreq = 0, len = 0, best = 0;
        vector<int> v(26, 0);
        
        for (auto i = 0; i < n; i++) {
            maxFreq = max(++v[s[i] - 'A'], maxFreq);
            len = i - left + 1;

            if (len - maxFreq > k && left < n) v[s[left++] - 'A']--;
            best = max(best, i - left + 1);
        };
        return best;
    };
};