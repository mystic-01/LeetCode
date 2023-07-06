class Solution {
public:
    void recurse(int idx, vector<int>& nums, int xorVal, int &ans) {
        if (idx == nums.size()) {
            ans += xorVal;
            return;
        };
        
        recurse(idx + 1, nums, nums[idx] ^ xorVal, ans);
        recurse(idx + 1, nums, xorVal, ans);
    };
    
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, xorVal = 0;
        recurse(0, nums, xorVal, ans);
        return ans;
    };
};