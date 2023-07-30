class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<int> distinct(2001, 0);

        for (int i = 0; i < n; i++) distinct[nums[i]] = 1;
        
        for (int i = 0; i < n; i++) {
            vector<int> curr(2001, 0);
            for (int j = i; j < n; j++) {
                curr[nums[j]] = 1;
                if (curr == distinct) count++;
            };
        };        
        
        return count;
    };
};