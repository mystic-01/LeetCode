class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            
            if (nums[i] >= n - i && (i == 0 || nums[i - 1] < n - i)) {
                return n - i;                    
            };            
        };
        return -1;
    };
};