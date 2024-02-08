class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        int count = 0;
        static vector<bool> nums(5 * 1e6 + 1, 0);

        if (nums[n - 1] == 0) {
            for (int i = 2; i < n; ++i) {
                if (!nums[i]) {
                    for (int j = 2; j * i < n; ++j) {
                        nums[j * i] = 1;
                    };
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



