class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), start = 0, end = 0, totSum = accumulate(nums.begin(), nums.end(), 0), sum = 0, best = 2147483647;        
        for (int end = 0; end < n; end++) {
            sum += nums[end];
            while (start <= end && sum > totSum - x) sum -= nums[start++];
            if (sum == totSum - x) best = min(best, n - (end - start + 1));            
        };
        return best == 2147483647 ? -1 : best;
    };
};