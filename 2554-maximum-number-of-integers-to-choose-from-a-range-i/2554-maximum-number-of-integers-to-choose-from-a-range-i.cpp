class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        sort(begin(nums), end(nums));
        int nSize = nums.size(), cd = 1, count = 0, sum = 0;
        for (int i = 0; i < nSize; ++i) {
            while (cd < nums[i]) {
                if (sum + cd <= maxSum && cd <= n) {
                    sum += cd, ++count, ++cd;    
                } else {
                    return count;
                };                
            };
            cd = nums[i] + 1;
        };
        while (cd < INT_MAX) {
            if (sum + cd <= maxSum && cd <= n) {
                sum += cd, ++count, ++cd;    
            } else {
                return count;
            };                
        };        
        return count;
    };
};