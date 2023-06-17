class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size(), minE = nums[0], maxE = nums[0];

        for (auto i = 0; i < n; i++) {
            if (nums[i] > minE && nums[i] < maxE) return nums[i];
            else if (nums[i] > maxE) {
                if (maxE > minE) return maxE;
                maxE = nums[i];
            } else if (nums[i] < minE) {
                if (minE < maxE) return minE;
                minE = nums[i];
            };
        };
        
        return -1;
    };
};