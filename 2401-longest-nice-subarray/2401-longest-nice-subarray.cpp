class Solution {
public:
    void updateBits(int &x, int *bits, bool &isBadBit, bool &addOrSubtract) {
        for (int i = 0; i < 32; ++i, x >>= 1) {
            if (x & 1) bits[i] += (addOrSubtract ? 1 : -1);
            if (bits[i] > 1) isBadBit = 1;    
        }; 
    };
    
    int longestNiceSubarray(vector<int>& nums) {
        int bits[32] = {0}, n =  nums.size(), left = 0, maxLen = 1, x = 0;
        bool isBadBit = 0, add = 1, subtract = 0;
        
        for (int right = 0; right < n; ++right) {
            isBadBit = 0, x = nums[right];
            updateBits(x, bits, isBadBit, add);

            while (left < n && isBadBit) {
                isBadBit = 0, x = nums[left];
                updateBits(x, bits, isBadBit, subtract);
                ++left;
            };
            maxLen = max(maxLen, right - left + 1);
        };
        return maxLen;
    };
};