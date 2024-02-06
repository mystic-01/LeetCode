class Solution {
public: 
    bool isPalindrome(string &s, int i, int j, int (*dp)[16]) {
        if (dp[i][j] != -1) {
            return dp[i][j];    
        };
        while (i < j) {
            if (s[i] != s[j]) {
                return dp[i][j] = 0;
            };
            i++, j--;
        };
        return dp[i][j] = 1;
    };  
        
    // pair<int, int> - Ingenious Harshit!!!!
    void solve(int idx, string &s, int n, vector<vector<string>>& ans, vector<pair<int, int>> &ds, int (*dp)[16]) {
        if(idx == n) {
            ans.push_back({});
            for (auto &[first, second] : ds) {
                string curr = s.substr(first, second - first + 1);
                ans.back().push_back(curr);
            };
        };
        
        for (auto i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i, dp)) {
                ds.push_back({idx, i});
                solve(i + 1, s, n, ans, ds, dp);
                ds.pop_back();
            };            
        };        
    };  
        
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<pair<int, int>> ds;
        int n = s.size(), dp[16][16];
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                dp[i][j] = -1;
            };        
        };
        solve(0, s, n, ans, ds, dp);
        return ans;
    };  
};      