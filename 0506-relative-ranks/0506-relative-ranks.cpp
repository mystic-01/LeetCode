class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> ans(n);
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[score[i]] = i;                
        };
        
        int count = 0;
        for (auto it = m.rbegin(); it != m.rend(); ++it, ++count) {
            if (count < 3) ans[it->second] = medals[count];                                         
            else ans[it->second] = to_string(count + 1);
        };
        return ans;
    };
};