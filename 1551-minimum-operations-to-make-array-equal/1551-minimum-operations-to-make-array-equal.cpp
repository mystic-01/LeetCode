class Solution {
public:
    int minOperations(int n) {
        int start = n % 2 ? 4 : 2, sum = 0;
        for (auto i = 0; i < n / 2; i++) sum += start, start += 4;
        return sum / 2;
    };
};