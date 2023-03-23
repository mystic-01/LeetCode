class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size(), totSum = 0, lSum = 0, temp = 0;
        for (auto &x : nums) totSum += x;
        for (auto &i : nums) temp = abs(totSum - i - lSum), lSum += i, totSum -= i, i = temp;
            
        return nums;
    };
};