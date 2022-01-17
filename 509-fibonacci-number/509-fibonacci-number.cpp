class Solution {
public:
    int fib(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n  -2);
    };
};