class Solution {
public:
    int kthFactor(int n, int k) {
        int ans = 0;
        for (int i = 1; i <= n && k; ++i) {
            if (n % i == 0) ans = i, --k;
        };
        return k == 0 ? ans : -1; 
    };
};