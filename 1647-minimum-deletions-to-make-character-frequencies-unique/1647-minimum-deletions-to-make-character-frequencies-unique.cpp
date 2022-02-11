class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        unordered_map<int, int> m;
        int n = s.length(), count = 0;
        
        for (auto i : s) v[i - 'a']++;
        
        for (auto i = 0; i < 26; i++) {
            while(v[i] != 0 && m.find(v[i]) != m.end()) v[i]--, count++;
            m[v[i]]++;
        };
        return count;
    };
};