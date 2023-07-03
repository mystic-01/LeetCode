class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool doesSomeElementOccurTwice = 0, freq[26] = {0};
        int n1 = s.size(), n2 = goal.size();
        vector<pair<char, char>> mismatch;
        
        if (n1 != n2) return 0;
        for (auto i = 0; i < n1; i++) {
            if (freq[s[i] - 'a'] == 1) doesSomeElementOccurTwice = 1;
            else freq[s[i] - 'a'] = 1;
            if (s[i] != goal[i]){
                if (mismatch.size() < 2) mismatch.push_back({s[i], goal[i]});
                else return false;
            };
        };        
        switch (mismatch.size()) {
            case 0:
                return doesSomeElementOccurTwice;
            case 1:
                return false;
            case 2:
                return mismatch[0].first == mismatch[1].second && mismatch[1].first == mismatch[0].second;
            default:
                return true;
        };
    };
};