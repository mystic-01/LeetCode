class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v(128, pair<int, char>(0, 'a'));                
        reverse(v.begin(), v.end());
        int n = s.length();
        
        for (auto i = 0; i < n; i++) v[s[i] - '0'].first++, v[s[i] - '0'].second = s[i];    
        sort(v.begin(), v.end());

        int j = 127;
        for (auto i = 0; i < n; i++) {
            s[i] = v[j].second;
            v[j].first--;
            if (v[j].first == 0) j--;
        };
        
        return s;
    };
};