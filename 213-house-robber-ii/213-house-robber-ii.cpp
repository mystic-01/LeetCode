class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return *max_element(nums.begin(), nums.end());
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0], dp[1] = nums[1];
        for (auto i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 2], dp[i - 1] - nums[i - 1]) + nums[i];
        };
        int ans1 = max(dp[n - 2], dp[n - 3]);
        
        dp[n - 1] = nums[n - 1], dp[n - 2] = nums[n - 2];
        for (auto i = n - 3; i > 0; i--) {
            dp[i] = max(dp[i + 2], dp[i + 1] - nums[i + 1]) + nums[i];
        };
        int ans2 = max(dp[1], dp[2]);
        
        return max(ans1, ans2);
    };
};

// class Solution {
// public:
//     int rob (vector<int> & house) {
//         int n = house.size();
//         vector<int> dp(n);
//         if(n == 1) return house[0];
//         int ans = max(house[0], house[1]);
//         if(n == 2) return ans;
//         dp[0] = house[0];
//         dp[1] = house[1];
        
// 	for(auto i = 2; i < n - 1; i++){
// 	dp[i] = max((dp[i-1] - house[i-1]), dp[i-2]) +house[i];
// 	ans = max(dp[i], ans);
// }
// dp[0] = house[1];
// dp[1] = house[2];
// ans = max( ans ,  house[2]);
// 	for(auto i = 2; i<n-1; i++){
// 	dp[i] = max((dp[i-1] - house[i]), dp[i-2]) +house[i + 1];
// 	ans = max(dp[i], ans);
// }
// return ans;

//     };
// };