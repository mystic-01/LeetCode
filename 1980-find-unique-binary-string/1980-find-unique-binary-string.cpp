class Solution {
public:
    void recurse(int i, int &n, set<string> &s, string &ans, string &ds) {
        // if (i > n) return;
            
        if (i == n) {
            if (s.find(ds) == s.end()) {
                ans = ds;    
            };   
            return;
        };
        
        ds += '1';
        if (!ans.size()) recurse(i + 1, n, s, ans, ds);
        ds.pop_back();
        ds += '0';
        if (!ans.size()) recurse(i + 1, n, s, ans, ds);
        ds.pop_back();
    };
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string ans = "", ds = "";
        set<string> s(nums.begin(), nums.end());
        recurse(0, n, s, ans, ds);
        return ans;
    };
};