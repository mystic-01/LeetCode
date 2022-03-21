class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> v(26, {-1, -1});
        int n = s.length();
        for (auto i = 0; i < n; i++) {
            if (v[s[i] - 'a'].first != -1) v[s[i] - 'a'].second = i;
            else v[s[i] - 'a'].first = v[s[i] - 'a'].second = i;
        };
        sort(v.begin(), v.end());
        vector<int> ans;
        
        int start = -1, end = -1;
        for (auto i = 0; i < 26; i++) {
            if (v[i].first == -1) continue;
            if (v[i].first > end) {
                if (end != -1) ans.push_back(end - start + 1);
                start = v[i].first, end = v[i].second; 
            };
            end = max(end, v[i].second);
        };
        if (end != -1) ans.push_back(end - start + 1);
        return ans;
    };
};