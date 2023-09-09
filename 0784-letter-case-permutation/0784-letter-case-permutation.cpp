class Solution {
public:
    void recurse(int idx, string &s, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        };
        
        recurse(idx + 1, s, ans);
        if (isalpha(s[idx])) {
            s[idx] += (s[idx] >= 'a' ? -32 : 32);
            recurse(idx + 1, s, ans);
            s[idx] += (s[idx] >= 'a' ? -32 : 32);
        };
    };
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        recurse(0, s, ans);
        return ans;
    };
};