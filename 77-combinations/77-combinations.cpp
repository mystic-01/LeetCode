class Solution {
public:
    void permute(int idx, int n, int k, vector<vector<int>> & ans, vector<int> ds) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        };
        
        for (auto i = idx; i <= n; i++) {
            ds.push_back(i);
            permute(i + 1, n, k, ans, ds);
            ds.pop_back();                
        };
    };
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;        
        vector<int> ds;
        permute(1, n, k, ans, ds);
        return ans;
    };
};