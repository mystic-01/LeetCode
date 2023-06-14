class Solution {
public:
    bool isPerfectSquare(int num) {
        for (auto i = 1; i <= num; i++) {
            long sq = (long)i * i;
            if (sq == num) return true;
            else if (sq > num) return false;
        };
        return false;
    };
};