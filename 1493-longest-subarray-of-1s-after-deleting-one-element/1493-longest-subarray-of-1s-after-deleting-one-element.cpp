class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int count = 0, best = 0, lastZeroAnswer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                lastZeroAnswer = count -= lastZeroAnswer;
            } else {
                count++;
            };
            
            best = max(best, count);
        };
        return best -= (best == nums.size());
    };
};