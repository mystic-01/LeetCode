// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
//         vector<int> copy = nums;
//         int prev1 = nums[0], prev2 = nums[1], ans = 0;
        
//         for (auto i = 2; i < n - 1; i++) nums[i] += prev1, prev1 = max(prev1, prev2), prev2 = nums[i];
//         for (auto i : nums) ans = max(ans, i);
        
//         prev1 = copy[n - 1], prev2 = copy[n - 2];
//         for (auto i = n - 3; i > 0; i--) copy[i] += prev1, prev1 = max(prev1, prev2), prev2 = copy[i];
        
//         for (auto i : copy) ans = max(ans, i);
//         return ans;
//     };
// };

class Solution {
public:
    int rob (vector<int> & house) {
        int n = house.size();
        vector<int> dp(n);
        if(n == 1) return house[0];
        int ans = max(house[0], house[1]);
        if(n == 2) return ans;
        dp[0] = house[0];
        dp[1] = house[1];
        
	for(auto i = 2; i < n - 1; i++){
	dp[i] = max((dp[i-1] - house[i-1]), dp[i-2]) +house[i];
	ans = max(dp[i], ans);
}
dp[0] = house[1];
dp[1] = house[2];
ans = max( ans ,  house[2]);
	for(auto i = 2; i<n-1; i++){
	dp[i] = max((dp[i-1] - house[i]), dp[i-2]) +house[i + 1];
	ans = max(dp[i], ans);
}
return ans;

    };
};