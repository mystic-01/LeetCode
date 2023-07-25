class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), best = 0, lis[n];                
        for (int i = 0; i < n; i++) lis[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) lis[i] = max(lis[i], lis[j] + 1);
            };
            best = max(best, lis[i] + 1);
        };
        
        return best;
    };
};