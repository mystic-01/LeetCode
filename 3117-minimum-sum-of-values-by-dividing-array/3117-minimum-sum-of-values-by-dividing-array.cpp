static const int oob = 1e9 + 1;

class Solution {
public:
    int getAns(int i, int k, int mIdx, vector<int> &nums, vector<int> &andValues, int &n, int &m, vector<vector<unordered_map<int, int>>> &dp) {
        if (i == n) {
            if (mIdx == m) return 0;
            else return oob;
        };
        if (mIdx >= m) {
            return oob;
        };
        if (dp[i][mIdx].find(k + 1) != dp[i][mIdx].end()) {
            return dp[i][mIdx][k + 1];
        };

        int take = oob;
        int startNew = oob;
        int andVal = k == -1 ? nums[i] : (k & nums[i]);
        if (n - i - 1 >= m - mIdx - 1) {
            take = getAns(i + 1, andVal, mIdx, nums, andValues, n, m, dp); 
        };
        if (andVal == andValues[mIdx]) {
            startNew = nums[i] + getAns(i + 1, -1, mIdx + 1, nums, andValues, n, m, dp);
        };

        return dp[i][mIdx][k + 1] = min(take, startNew);
    };
    
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(m + 1));
        int ans = getAns(0, -1, 0, nums, andValues, n, m, dp);           
        return ans >= oob ? -1 : ans;
    };
};



