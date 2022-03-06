class Solution {
public:
    int countOrders(int n) {
        long long res = 1, mod = 1e9 + 7;
        for( auto i = 1; i <= n; i++) {
            res *= i;
            res %= mod;
            res *= (2 * i - 1);
            res %= mod;
        };
        return (int)res % mod;
    };
};