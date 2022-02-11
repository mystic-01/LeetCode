class Solution {
public:
    int minDeletions(string s) {
        int v[26] = {0};
        unordered_map<int, int> m;
        int n = s.length(), count = 0;
        
        for (auto i : s) v[i - 'a']++;
        
        for (auto i = 0; i < 26; i++) {
            while(v[i] && m[v[i]]) v[i]--, count++;
            m[v[i]]++;
        };
        return count;
    };
};