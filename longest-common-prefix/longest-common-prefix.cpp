class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans, temp = strs[0];
        int tempIndex = 0;
        for (auto i = 1; i < strs.size(); i++) {
            if (strs[i].length() < temp.length()) {
                temp = strs[i];
                tempIndex = i;
            };
        };
        for (auto i = 1; i <= temp.length(); i++) {
            ans = temp.substr(0, i);
            for (auto j = 0; j < strs.size(); j++) {
                if (strs[j].substr(0, i) != ans) {
                    return ans.substr(0, ans.length() - 1);
                };
            };
        };
        return ans;
    };
};