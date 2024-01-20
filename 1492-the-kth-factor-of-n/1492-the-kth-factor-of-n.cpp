class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1, ans = 0;
        while (i <= n && k) {
            if (n % i == 0) ans = i, --k;
            ++i;
        };
        return k == 0 ? ans : -1; 
    };
};