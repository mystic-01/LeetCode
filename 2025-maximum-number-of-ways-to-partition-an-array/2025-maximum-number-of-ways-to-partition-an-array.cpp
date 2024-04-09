class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, ansIfChanged[n];
        memset(ansIfChanged, 0, sizeof(ansIfChanged));
        long long lSum[n];
        unordered_map<long long, vector<int>> m;

        for (int i = 0; i < n; ++i) {
            lSum[i] = (i > 0 ? lSum[i - 1] + nums[i]: nums[i]);
            m[k - nums[i]].push_back(i);
        };
        
        for (int i = 1; i < n; ++i) {
            long long left = lSum[i - 1], right = lSum[n - 1] - lSum[i - 1];
            count += left == right;

            long long diff1 = left - right;
            for (int &idx : m[diff1]) {
                if (idx >= i) {
                    ++ansIfChanged[idx];
                };                   
            };
            long long diff2 = right - left;
            for (int &idx2 : m[diff2]) {
                if (idx2 < i) {
                    ++ansIfChanged[idx2];
                };                   
            };            
        };
        for (int i = 0; i < n; ++i) {
            count = max(count, ansIfChanged[i]);
        };        
        return count;
    };
};


// arr  2  -1  2
// lsum 2   1  3
// abs  1   4  1
    
    
//     p1
//     2, 1
    
//     p2
//     1, 2