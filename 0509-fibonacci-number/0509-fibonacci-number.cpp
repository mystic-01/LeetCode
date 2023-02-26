class Solution {
public: 
    int fib(int n) {
        int arr[2] = {0, 1};
        for (auto i = 2; i <= n; i++) arr[i % 2] = arr[(i - 2) % 2] + arr[(i - 1) % 2];
        return arr[n % 2];
    };
};