class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), zero[n], one[n], ans = 0;
        fill(zero, zero + n, 0);
        fill(one, one + n, 0);
        for (int i = 0; i < n - 1; ++i) {
            zero[i] = (s[i] == '0' ? 1 : 0) + (i - 1 >= 0 ? zero[i - 1] : 0);
        };
        for (int i = n - 1; i > 0; --i) {
            one[i] += ((s[i] == '1' ? 1 : 0) + (i + 1 < n ? one[i + 1] : 0));
            ans = max(ans, one[i] + zero[i - 1]);
        };        
        return ans;                         
    };
};