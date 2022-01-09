class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        vector<string> ans(n);
        for (auto i = 0; i < n; i++)
            ans[i] = ((i+1) % 3 == 0 && (i+1) % 5 == 0) 
                ? "FizzBuzz"
                : (i+1) % 3 == 0 
                    ? "Fizz" 
                    : (i+1) % 5 == 0 
                        ? "Buzz"
                        : to_string(i + 1);
        return ans;
    };
};