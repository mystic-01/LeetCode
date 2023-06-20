class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, digitSum = 0;
        for (auto &x : nums) {
            sum += x;
            while (x) digitSum += (x % 10), x /= 10;
        };
        return abs(sum - digitSum);
    };
};