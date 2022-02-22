class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length(), ans = 0;
        for (auto i = 0; i < n; i++) {
            int val = (columnTitle[i] - 'A') + 1;
            ans += (val * pow(26, n - i - 1));
        };
        return ans;
    };
};