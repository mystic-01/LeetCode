static int mod = 1e9 + 7;

class Solution {
public:
    long long powerOf2(int power) {
        if (power <= 1) {
            return power + 1;    
        };
        if (power % 2 == 0) {
            long long temp = powerOf2(power / 2);
            return (temp * temp) % mod;
        } else {
            return (2 * powerOf2(power - 1)) % mod;     
        };
    };
    
    int recurse(int idx, int target, int count, int &n, vector<int> &nums, vector<vector<vector<int>>> &dp) {
        if (target == 0) {
            return powerOf2(n - count);    
        };
        if (idx == n) {
            return 0;    
        };
        
        if (dp[idx][target][count] != -1) {
            return dp[idx][target][count];                
        };
        
        int take = 0, notTake = 0;
        if (target - nums[idx] >= 0) {
            take = recurse(idx + 1, target - nums[idx], count + 1, n, nums, dp);
        };
        notTake = recurse(idx + 1, target, count, n, nums, dp);
        return dp[idx][target][count] = (take + notTake) % mod;
    };
    
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return recurse(0, k, 0, n, nums, dp);
    };
};


/*

1 2 
3
3

3C0 -> 1
3C1 -> 3
3C2 -> 3
3C3 -> 1

E2 (1 + 1 + 2)
count[ans[i].size() to end]++

4C0 -> 1
4C1 -> 4
4C2 -> 6 - count[2]
4C3 -> 4 - count[3] - count[2] - count[1]


*/