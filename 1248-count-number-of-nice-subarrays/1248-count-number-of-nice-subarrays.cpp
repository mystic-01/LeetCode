class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), odd = 0, left = -1, right = -1, count = 0;
        
        for (auto i = 0; i < n; i++) {
            if (nums[i] % 2)  {
                odd++;
                if (right == -1) right = i;
            };            
            
            if (odd > k) {
                left = right;
                right++;
                while (right < n && nums[right] % 2 == 0) right++;
                odd--;
            };
            if (odd == k) count += right - left;
        };
        return count;
    };
};