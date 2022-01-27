class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, best = 0, zeroCount = 0, lastZeroIndex = 0;
        vector<int> v;
        for (auto i = 0; i < n; i++) {
            if (!nums[i]) {
                if (zeroCount > k) lastZeroIndex++;
                zeroCount++;
                v.push_back(i + 1);
            };
            ans = i + 1 - ((zeroCount > k) ? v[lastZeroIndex] : 0);
            best = max(best, ans);
        };
        return best;
    };
};