class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int count = 0, best = 0, lastZeroAnswer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                count -= lastZeroAnswer;
                lastZeroAnswer = count;
            } else {
                count++;
            };
            
            best = max(best, count);
        };
        return best == nums.size() ? best - 1 : best;
    };
};