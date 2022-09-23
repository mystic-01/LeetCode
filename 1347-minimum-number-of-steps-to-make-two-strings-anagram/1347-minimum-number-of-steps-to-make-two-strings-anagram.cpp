class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), v[26] = {0}, steps = 0;
        
        for (auto i = 0; i < n; i++) v[s[i] - 'a']++, v[t[i] - 'a']--;

        for (auto i = 0; i < 26; i++) steps += abs(v[i]);

        return steps / 2;
    };
};