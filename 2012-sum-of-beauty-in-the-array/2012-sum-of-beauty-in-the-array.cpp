class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), beauty = 0, count[n];
        for (int i = 0; i < n; ++i) {
            count[i] = 0;
        };        
        
        int currMax = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > currMax) currMax = nums[i], count[i] += 1;            
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) ++beauty;            
        };
        
        int currMin = nums[n - 1];                                                          
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < currMin) currMin = nums[i], count[i] += 1;            
            if (count[i] == 2) ++beauty;
        };
        return beauty;
    };
};