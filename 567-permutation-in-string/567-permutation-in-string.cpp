class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // window mein count 0 toh true else false.
        int v[26] = {0}, n1 = s1.length(), n2 = s2.length();
        for (auto i : s1) v[i - 'a']++;
        
        for (auto i = 0; i < n2; i++) {
            v[s2[i] - 'a']--;
            if (i >= n1) v[s2[i - n1] - 'a']++;
            if (i >= n1 - 1) {
                auto j = 0;
                while (j < 26 && !v[j]) j++;
                if (j == 26) return 1;
            };
        };
        return 0;
    };
};