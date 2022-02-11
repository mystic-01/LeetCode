class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int v[26] = {0}, n1 = p.length(), n2 = s.length();
        for (auto i : p) v[i - 'a']++;
        
        for (auto i = 0; i < n2; i++) {
            v[s[i] - 'a']--;
            if (i >= n1) v[s[i - n1] - 'a']++;
            if (i >= n1 - 1) {
                auto j = 0;
                while (j < 26 && v[j++] == 0);
                if (j == 26) ans.push_back(i - n1 + 1);
            };    
        };
        return ans;
    };
};