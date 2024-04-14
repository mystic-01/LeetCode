static const int oob = 1e9 + 1;

class Solution {
public:
    int getAns(int i, int k, int mIdx, vector<int> &nums, vector<int> &andValues, int &n, int &m,           
               vector<vector<unordered_map<int, int>>> &dp) {
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
        take = getAns(i + 1, andVal, mIdx, nums, andValues, n, m, dp); 
        
        if (andVal == andValues[mIdx]) {
            startNew = nums[i] + getAns(i + 1, -1, mIdx + 1, nums, andValues, n, m, dp);
        };

        return dp[i][mIdx][k + 1] = min(take, startNew);
    };
    
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        // vector<vector<int>> dp(1e5 + 2, vector<int>(m + 1, oob)), prev(1e5 + 2, vector<int>(m + 1, oob));

//         unordered_set<int> s; 
//         for (int i = 0; i < n; ++i) {
//             int andVal = nums[i];
//             for (int j = i; j < n; ++j) {
//                 anddVal
//                 s.insert()
//             };
//         };
        
//         for (int k = 1e5; k >= -1; --k) {
//             prev[k + 1][m] = 0; 
//         };

        
//         for (int i = n - 1; i >= 0; --i) {
//             for (int k = 1e5; k >= -1; --k) {
//                 for (int mIdx = m - 1; mIdx >= 0; --mIdx) {
//                     int take = oob;
//                     int startNew = oob;
//                     int andVal = k == -1 ? nums[i] : (k & nums[i]); 
//                     take = prev[andVal][mIdx];
//                     if (andVal == andValues[mIdx]) {
//                         startNew = nums[i] + prev[0][mIdx + 1];
//                     };
//                     dp[k + 1][mIdx] = min(take, startNew);
//                 };            
//             };        
//             prev = dp;
//         };        
        // int ans = prev[0][0];
        vector<vector<unordered_map<int, int>>> dp(n + 1, vector<unordered_map<int, int>>(m + 1));
        int ans = getAns(0, -1, 0, nums, andValues, n, m, dp);           
        return ans >= oob ? -1 : ans;
    };
};



