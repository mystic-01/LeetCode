class Solution {
public:
    void findCombination(int i, int t, int k, vector<vector<int>> &ans, vector<int> ds) {
        if (t == 0 && ds.size() == k) ans.push_back(ds);
       
        if (i == 10 || i > t || ds.size() > k) return;
         
        // Here i is the current value ranging from 1 to 9 and  
        // if reaches 10, then it is similar to idx reaching nums.size(), so we return.
        // And if i becomes more than the current target that is left, then also we return.        
        // Lastly, if we have more elements in ds than k, we return.
        
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