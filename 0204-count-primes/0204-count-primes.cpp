class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> nums(n, 0);

        for (int i = 2; i < n; ++i) {
            if (!nums[i]) {
                for (int j = 2; j * i < n; ++j) {
                    nums[j * i] = 1;
                };
            };
        };
        for (int i = 2; i < n; ++i) {
            if (!nums[i]) {
                ++count;
            };
        };
        return count;
    };
};
