class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (auto i = 0; i <= n; i++) {
            int x = i, ones = 0;
            while (x) {
                ones += x % 2;
                x /= 2;
            };
            ans.push_back(ones);
        };
        return ans;
    };
};
