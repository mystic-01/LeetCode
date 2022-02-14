class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (true) {
            if (n == 1) return 1;
            int num = 0;
            while (n) {
                num += (pow(n % 10, 2));
                n /= 10;
            };
            n = num;
            if (++m[num] > 1) return 0;
        };
        return 0;
    };
};