class Solution {
public:
    int mod = 1e9 + 7;
    
    long recurse(int num, set<int> &values, map<int, long> &dp) {
        if (dp.find(num) != dp.end()) {
            return dp[num];    
        };
        
        long ans = 1, squareRoot = sqrt(num);
        for (int i = 2; i <= squareRoot; ++i) {
            if (num % i == 0) {
                if (values.find(i) != values.end() && values.find(num / i) != values.end()) {
                    if (i != num / i) {
                        ans = (ans + recurse(i, values, dp) * recurse(num / i, values, dp) * 2) % mod;         
                    } else {
                        ans = (ans + recurse(i, values, dp) * recurse(i, values, dp)) % mod;         
                    };
                };    
            };                
        };
        return dp[num] = ans;
    };
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        set<int> values(begin(arr), end(arr));
        map<int, long> dp;     
        long ans = 0;
        for (auto &num : values) {
            ans = (ans + recurse(num, values, dp)) % mod;         
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




