class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size(), prev = 0, curr = 0, count = 0, best = 0;
        for (auto i = 0; i < n - 1; i++) {
            curr = nums[i] - nums[i + 1];
            if (prev > 0) {
                if (curr > 0) count = 1;
                if (curr < 0) count++;
            } else if (prev < 0) {
                if (curr < 0) count = 1;
                if (curr > 0) count++;
            } else if (prev == 0) {
                count = 1;
                if (curr == 0) {
                    count = 0;
                };
            };
            best = max(best, count);
            prev = curr;
        };
        return max(++best, 1);
    };
};