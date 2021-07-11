class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans = s;
        for (int i = 0; i < s.length(); i++) {
            ans[indices[i]] = s[i];
        };
        return ans;
    };
};