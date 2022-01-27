class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), best = 0, zeroCount = 0, lastZeroIndex = 0;
        vector<int> v;
        for (auto i = 0; i < n; i++) {
            if (!nums[i]) {
                if (zeroCount++ > k) lastZeroIndex++;
                v.push_back(i + 1);
            };
            best = max(best, i + 1 - ((zeroCount > k) ? v[lastZeroIndex] : 0));
        };
        return best;
    };
};