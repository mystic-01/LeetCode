class Solution {
public:
    int mod = 1e9 + 7;
    
    long recurse(int num, map<int, long> &dp) {
        if (dp[num] != 0) {
            return dp[num];    
        };
        
        long ans = 1, squareRoot = sqrt(num);
        for (int i = 2; i <= squareRoot; ++i) {
            if (num % i == 0) {
                if (dp.find(i) != dp.end() && dp.find(num / i) != dp.end()) {
                    if (i != num / i) {
                        ans = (ans + recurse(i, dp) * recurse(num / i, dp) * 2) % mod;         
                    } else {
                        ans = (ans + recurse(i, dp) * recurse(i, dp)) % mod;         
                    };
                };    
            };                
        };
        return dp[num] = ans;
    };
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long> dp;     
        long ans = 0;
        for (auto &x : arr) {
            dp[x] = 0;
        };
        for (auto it = dp.rbegin(); it != dp.rend(); ++it) {
            ans = (ans + recurse(it->first, dp)) % mod;         
        };
        return ans;        
    };
};

/*
    20 -> 2 * 10 | 4 * 5

    20         24
   2  10      4   6
      2  5   2 2  3 2
      
      
      2 -> 1
      3 -> 1
      4 -> 2
      6 -> 3
      24 -> 13
      
      24    24     24       24         24         24          24        24      24        24       24       24     24
           4  6   6  4     4   6      4   6      6   4      6   4      4  6    4  6      6  4     6   4    4  6   6  4
                          2 2  3 2   2 2  2 3   3 2  2 2   2 3  2 2      3 2     2  3   3 2      2 3      2 2        2 2
*/




