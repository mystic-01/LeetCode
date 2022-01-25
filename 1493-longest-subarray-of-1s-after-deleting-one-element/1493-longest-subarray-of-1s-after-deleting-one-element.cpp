class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int lastZero = -1, count = 0, best = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count -= m[lastZero];
                lastZero = i;
            } else {
                count++;
            }        
            m[i] = count;
            best = max(best, count);
        };
        return lastZero == -1 ? best - 1 : best;
    };
};