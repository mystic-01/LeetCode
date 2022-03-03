class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int diff = nums[1] - nums[0], left = 0, count = 0;
        
        for (auto i = 2; i < n; i++) {
            int currDiff = nums[i] - nums[i - 1]; 
            
            if (currDiff != diff) diff = currDiff, left = i - 1;

            int window = i - left + 1;
            if (window >= 3) count += (window - 3  + 1);
        };
        
        return count;
    };
};