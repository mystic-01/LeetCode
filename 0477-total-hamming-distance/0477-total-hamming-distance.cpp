class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (auto i = 0; i < 32; i++) {
            int count = 0;
            for (auto j = 0; j < n; j++) {
                count += (nums[j] & 1), nums[j] /= 2;    
            };    
            ans += (count * (n - count));
        };
        return ans;
    };
};