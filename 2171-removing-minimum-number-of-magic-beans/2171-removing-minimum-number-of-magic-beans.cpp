class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        long long n = nums.size(), totalSum = 0, maxBeansLeft = 0;
        sort(nums.begin(), nums.end());
        
        for (auto i : nums) totalSum += i;
 
        for (auto i = 0; i < n; i++) maxBeansLeft = max(maxBeansLeft, nums[i] * (n - i));
        return totalSum - maxBeansLeft;   
    };
};
