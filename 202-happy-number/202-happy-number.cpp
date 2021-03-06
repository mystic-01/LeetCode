class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            if (n == 1) return 1;
            if (s.insert(n).second == 0) return 0;
            int num = 0;
            while (n) {
                num += (pow(n % 10, 2));
                n /= 10;
            };
            n = num;
        };
        return 0;
    };
};