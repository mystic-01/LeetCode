class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        long long n = nums.size(), totalSum = 0, curr = LLONG_MAX, best = LLONG_MAX;
        sort(nums.begin(), nums.end());
        
        for (auto i : nums) totalSum += i;
 
        for (auto i = 0; i < n; i++) {
            curr = totalSum - (nums[i] * (n - i));
            best = min(best, curr);
        };
        return best;   
    };
};
