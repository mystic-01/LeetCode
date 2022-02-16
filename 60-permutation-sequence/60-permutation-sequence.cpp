class Solution {
public:
//     void solve(int idx, int n, vector<string>& ans, string ds) {
//         if (idx == n) ans.push_back(ds);
        
//         for (auto i = idx; i < n; i++) {
//             swap(ds[idx], ds[i]);
//             solve(idx + 1, n, ans, ds);            
//             swap(ds[idx], ds[i]);
//         };
//     };            
    
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int fact = 1;
        for (auto i = 0; i < n; i++) nums[i] = (i + 1), fact *= (i + 1);
        string ans = "";
        k -= 1;
        
        while (nums.size()) {
            fact = fact / nums.size();
            ans += to_string(nums[k / fact]);     
            nums.erase(nums.begin() + k / fact);
            k = k % fact;
        };
        
        return ans;
    };
};