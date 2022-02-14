class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), totalOnes = 0, totalZeroes = 0, best = INT_MAX;
        
        for (auto i : nums) if (i) totalOnes++; else totalZeroes++;
        
        // For Ones
        int zeroCount = 0, left = 0;
        for (auto i = 0; i < n; i++) {
            if (!nums[i]) zeroCount++;
            while (i - left + 1 > totalOnes && left < n) {
                if (nums[left++] == 0) zeroCount--;
            };
            if (i - left + 1 == totalOnes) best = min(best, zeroCount);
        }; 
        // For Zeroes
        int oneCount = 0; left = 0;
        for (auto i = 0; i < n; i++) {
            if (nums[i]) oneCount++;
            while (i - left + 1 > totalZeroes && left < n) {
                if (nums[left++] == 1) oneCount--;
            };
            if (i - left + 1 == totalZeroes) best = min(best, oneCount);
        }; 
        return best;  
    };
};