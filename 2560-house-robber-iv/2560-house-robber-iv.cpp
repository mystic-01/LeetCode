class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), lo = 1, hi = 1e9, ans = 2147483647;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo, taken = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) taken++, i++;
            };
            
            if (taken >= k) hi = mid - 1, ans = min(ans, mid);
            else lo = mid + 1;
        };
        
        return ans; 
    };
};                               
                               
                               
                               