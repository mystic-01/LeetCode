class Solution {
public:
    // Lomgest valid mountain subsequence
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), best = 0;
        vector<int> left(n, 0), right(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                };        
            };        
        };
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                };        
            };        
            if (left[i] && right[i]) best = max(best, left[i] + right[i] + 1);
        };
        
        return n - best;
    };
};