class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = -1, secondMax = -1;
        for (int &x : nums) {
            if (x >= maxNum) secondMax = maxNum, maxNum = x;
            else if (x >= secondMax) secondMax = x;
        };
        return (maxNum - 1) * (secondMax - 1);
    };
};