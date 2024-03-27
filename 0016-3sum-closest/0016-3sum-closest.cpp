class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = 1e9;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n - 2; ) {
            int a = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                int b = nums[j], c = nums[k], sum = a + b + c;
                
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                };
                if (sum > target) {
                    --k;
                    while (k >= 0 && nums[k] == nums[k + 1]) {
                        --k;                        
                    };
                } else {
                    ++j;    
                    while (j < n && nums[j - 1] == nums[j]) {
                        ++j;                        
                    }; 
                };               
            };
            ++i;    
            while (i < n && nums[i - 1] == nums[i]) {
                ++i;                        
            };             
        };
        return ans;
    };
};