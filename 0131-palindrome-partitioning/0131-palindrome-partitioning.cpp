class Solution {
public: 
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        };
        return true;
    };  
        
    void solve(int idx, string &s, int n, vector<vector<string>>& ans, vector<pair<int, int>> &ds) {
        if(idx == n) {
            ans.push_back({});
            for (auto &[first, second] : ds) {
                string curr = s.substr(first, second - first + 1);
                ans.back().push_back(curr);
            };
        };
        
        for (auto i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                ds.push_back({idx, i});
                solve(i + 1, s, n, ans, ds);
                ds.pop_back();
            };            
        };        
    };  
        
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<pair<int, int>> ds;
        int n = s.length();
        solve(0, s, n, ans, ds);
        return ans;
    };  
};      