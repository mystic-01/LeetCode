class Solution {
public:
    int maxScore(vector<int>& nums, int k) {        
        int n = nums.size(), m = n + 1, count = 0, best = 0;

        vector<int> left(n + 1, 0), right(n + 1, 0);
        
        for (auto i = 1; i < n + 1; i++) {
            left[i] += (left[i - 1] + nums[i - 1]);           
            right[n - i] += (right[n + 1 - i] + nums[n - i]);           
        };
       
        int  lo = k, hi = n;
        while (lo >= 0) {
            count = left[lo--] + right[hi--];
            best = max(best, count);
        };
        return best;
    };
};