class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& nums) {
        int n = nums.size(), j = 0;
        vector<int> ans(n, -1);
        sort(begin(nums), end(nums));
        
        bool take = true;
        for (int i = 0; j < n; ++i) {
            int idx = i % n;
            if (ans[idx] == -1) {
                if (take) {
                    ans[idx] = nums[j++];
                };
                take = !take;
            };
        };
        return ans;
    };
};