class Solution {
public:
    string recurse(int i, int &n, vector<string> &s, string &ds) {
        if (i == n) {
            if (ds.size() == n && find(s.begin(), s.end(), ds) == s.end()) {
                string ans = "";
                ans += ds;
                return ans;
            };    
            return "";
        };
        
        string ans = "";
        ds += '1';
        ans = recurse(i + 1, n, s, ds);
        ds.pop_back();
        if (ans.size()) return ans;
        
        ds += '0';
        ans = recurse(i + 1, n, s, ds);
        ds.pop_back();
        return ans;
    };
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string ds = "";
        return recurse(0, n, nums, ds);
    };
};