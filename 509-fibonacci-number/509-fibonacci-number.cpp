class Solution {
public: 
    int fib(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        vector<int> smartIfa = {0, 1};
        for (int i = 2; i <= n; i++) smartIfa = {smartIfa[1], smartIfa[1] + smartIfa[0]};
        return n < 2 ? n : smartIfa[1];
    };
};