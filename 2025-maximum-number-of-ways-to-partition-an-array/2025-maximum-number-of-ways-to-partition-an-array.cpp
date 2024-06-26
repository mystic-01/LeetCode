class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, ansIfChanged[n];
        memset(ansIfChanged, 0, sizeof(ansIfChanged));
        unordered_map<long long, vector<int>> m;

        long long totSum = 0, lSum = 0;
        for (int i = 0; i < n; ++i) {
            totSum += nums[i];
            m[k - nums[i]].push_back(i);
        };
        
        for (int i = 1; i < n; ++i) {
            lSum += nums[i - 1];
            long long left = lSum, right = totSum - lSum;

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