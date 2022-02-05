class Solution {
public:
    void findCombination(int i, int t, int k, vector<vector<int>> &ans, vector<int> ds) {
        if (t == 0 && ds.size() == k) ans.push_back(ds);
       
        if (i == 10 || i > t || ds.size() > k) return;
        
        ds.push_back(i);
        findCombination(i + 1, t - i, k, ans, ds);
        ds.pop_back();
        findCombination(i + 1, t, k, ans, ds);        
    };
    
    vector<vector<int>> combinationSum3 (int k, int target) {
        vector<vector<int>> ans;
        vector<int> ds;        
        findCombination(1, target, k, ans, ds);                
        return ans;
    };
};