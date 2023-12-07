class Solution {
public:
    void updateBits(int &x, int *bits, bool &isBadAddition, bool &addOrSubtract) {
        for (int i = 0; i < 32; ++i, x >>= 1) {
            if (x & 1) bits[i] += (addOrSubtract ? 1 : -1);
            if (bits[i] > 1) isBadAddition = 1;    
        }; 
    };
    
    int longestNiceSubarray(vector<int>& nums) {
        int bits[32] = {0}, n =  nums.size(), left = 0, maxLen = 1;
        for (int right = 0; right < n; ++right) {
            int x = nums[right];
            bool isBadAddition = 0, add = 1, subtract = 0;
            
            updateBits(x, bits, isBadAddition, add);

            while (left < n && isBadAddition) {
                isBadAddition = 0, x = nums[left];
                updateBits(x, bits, isBadAddition, subtract);
                ++left;
            };
            maxLen = max(maxLen, right - left + 1);
        };
        return maxLen;
    };
};