class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), sumL = 0, sumR = 0;
        vector<int> left(n), right(n);
        
        for (auto i = 0; i < n; i++) {
            sumL += nums[i];
            left[i] = sumL;
            sumR += nums[n - i - 1];
            right[n - i - 1] = sumR;
        };                        
        for (auto i = 0; i < n; i++) if (left[i] == right[i]) return i;
        return -1;
    };
};