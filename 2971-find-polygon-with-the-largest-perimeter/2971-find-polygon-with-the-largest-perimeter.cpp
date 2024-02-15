class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long ans = -1, sum[n];
        fill(sum, sum + n, 0);
        sum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + (long long)nums[i];
        };
        
        for (int i = 2; i < n; ++i) {
            if (nums[i] < sum[i - 1]) {
                ans = sum[i];    
            };
        };        
        return ans;
    };
};

// 1 1 2 3 5  12 50
// 1 2 4 7 12 24 74
