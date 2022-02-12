class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size(), curr = 0, h = 0;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < n; i++) {
            curr = min(nums[i], n - i);
            h = max(curr, h);
        };
        return h;
    };
};