class Solution {
public:
    void recurse(int idx, int &n, int &k, vector<vector<int>> &ans, vector<int> &ds) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        };
        
        ds.push_back(idx);
        if (idx <= n) recurse(idx + 1, n, k, ans, ds);
        ds.pop_back();
        if (idx <= n) recurse(idx + 1, n, k, ans, ds);        
    };
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        recurse(1, n, k, ans, ds);
        return ans;
    };
};