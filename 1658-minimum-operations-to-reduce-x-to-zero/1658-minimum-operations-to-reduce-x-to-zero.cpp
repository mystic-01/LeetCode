class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, totalSum = 0, left = 0, best = INT_MIN;
        for (auto i = 0; i < n; i++) totalSum += nums[i];            
        
        int k = totalSum - x;
        if (x > totalSum) return -1; 
        for (auto i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > k && left < n) sum -= nums[left++];
            if (sum == k) best = max(best, i - left + 1);
        };
        return best == INT_MIN ? -1 : n - best;
    };
};