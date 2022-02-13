class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
//         long long n = nums.size(), count = 0, idx = 0, prefixSum = 0;
//         sort(nums.begin(), nums.end());
        
//         for (auto i = 0; i + 1 < n; i++) {
//             prefixSum += nums[i];
//             int diff = nums[i + 1] - nums[i];
//             if (nums[i] < diff * (n - i - 1)) count = prefixSum, idx = i + 1;                                                           
//         }; 
//         cout << count << " " << idx;
//         for (auto i = idx; i < n; i++) {
//             count += (nums[i] - nums[idx]);                                                          
//         }; 
//         return count;  
        long long n = nums.size(), count = 0, idx = 0, curr = 0, best = LLONG_MAX, totalSum = 0;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < n; i++) totalSum += nums[i]; 
        
        for (auto i = 0; i < n; i++) {
            curr = (totalSum - (nums[i] * (n - i)));
            best = min(best, curr);
        }; 
        return best;  
    };
};