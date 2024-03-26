class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        unordered_set<int> s(begin(nums), end(nums));
        int count = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (sum + i <= maxSum && s.count(i) == 0) {
                ++count, sum += i;    
            };
        };
        return count;
    };
};