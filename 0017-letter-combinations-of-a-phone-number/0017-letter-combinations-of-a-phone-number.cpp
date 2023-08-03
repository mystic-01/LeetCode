class Solution {
public:
    void recurse(int idx, string *alphas, string &digits, string &ds, vector<string> &ans) {
        if (idx == digits.size()) {
            if (ds.size()) ans.push_back(ds);
            return;
        };
        
        int num = digits[idx] - '0';
        for (int i = 0; i < alphas[num].size(); i++) {
            ds.push_back(alphas[num][i]);
            recurse(idx + 1, alphas, digits, ds, ans);
            ds.pop_back();
        };
        
    };
    
    
    vector<string> letterCombinations(string &digits) {
        vector<string> ans;            
        string alphas[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ds = "";
        recurse(0, alphas, digits, ds, ans);
        return ans;
    };
};