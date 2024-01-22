class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long n = nums.size(), expectedSum = (n * (n + 1)) / 2, sum = 0;
        long expectedSqSum = (n * (n + 1) * (2 * n + 1)) / 6, sqSum = 0;

        for (int &x : nums) {
            sqSum += (x * x), sum += x;
        };
        int sumDiff = expectedSum - sum, sqSumDiff = expectedSqSum - sqSum;
        int a = (pow(sumDiff, 2) - sqSumDiff) / (2 * sumDiff);
        return {abs(a), abs(a) + sumDiff};
    };
};