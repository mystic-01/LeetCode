class Solution {
public: 
    // bool isPalindrome(string s) {
    //     int i = 0, j = s.length() - 1;
    //     while (i < j) {
    //         if (s[i] != s[j]) return 0;
    //         i++, j--;
    //     };
    //     return 1;
    // };  
        
    void solve(int idx, string s, int n, vector<vector<string>>& ans, vector<string> ds) {
        if(idx == n) ans.push_back(ds);
        
        for (auto i = idx; i < n; i++) {
            int k = idx, j = i, flag = 1;
            while (k < j) {
                if (s[k] != s[j]) flag = 0;
                k++, j--;
            };
            if (flag) {
                ds.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, n, ans, ds);
                ds.pop_back();
            };            
        };        
    };  
        
//         
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.length();
        solve(0, s, n, ans, ds);
        return ans;
    };  
};      