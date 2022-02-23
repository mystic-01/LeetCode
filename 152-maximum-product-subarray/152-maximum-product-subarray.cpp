class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
//         // simple kadane won't work here. Need to take care of those negative mfs.
//         for (auto i : nums) {
//             prod = max(prod * i, i);
//             best = max(best, prod);
//         };
//         return best;
        
        int minPro = nums[0], maxPro = nums[0], ans = nums[0];
        for(auto i = 1; i < n; i++){
            if(nums[i] < 0) swap(maxPro, minPro);
            maxPro = max(maxPro* nums[i], nums[i]);
            minPro = min(minPro * nums[i], nums[i]);
            ans = max(ans, maxPro);
        }
        return ans;
    };
}; 