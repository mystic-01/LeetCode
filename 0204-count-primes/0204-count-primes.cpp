class Solution {
public:
    int countPrimes(int n) {
        int count = 0, nLimit = 5 * 1e6;
        static vector<bool> nums(nLimit, 0);
        static int marked = 0;
        if (n < 2) return 0;

        if (!marked++) {
            for (int i = 2; i < nLimit; ++i) {
                if (!nums[i]) {
                    for (int j = 2; j * i < nLimit; ++j) {
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



