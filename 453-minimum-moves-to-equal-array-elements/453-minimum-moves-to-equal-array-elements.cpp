class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), currDiff = 0, totalDiff = 0;
        
        sort(nums.begin(), nums.end());
        for (auto i = 0; i + 1 < n; i++) {
            currDiff += (nums[i + 1] - nums[i]);            
            totalDiff += currDiff;
        };
        
        return totalDiff;
    };
};