class Solution {
public:
    // Lomgest valid mountain subsequence
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), best = 0;
        vector<int> lis, len(n);
            
        // Find max no of increasing elements (more formally, lis subsequence) on the 'left' of the element. 
        for (int i = 0; i < n; i++) {
            if (lis.empty() || nums[i] > lis.back()) lis.push_back(nums[i]);
            else {
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            };
            len[i] = lis.size();
        };
        
        lis.clear();
        
        // Find max no of increasing elements on the 'right' of the element. 
        for (int i = n - 1; i >= 0; i--) {
            if (lis.empty() || nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            };
            if (len[i] > 1  && lis.size() > 1) best = max(best, len[i] + (int)lis.size() - 1);
        };
        
        return n - best;
    };
};

/*
class Solution {
public:
    // Lomgest valid mountain subsequence
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), best = 0;
        int left[n], right[n];
        
        for (int i = 0; i < n; i++) left[i] = 0, right[i] = 0;

            
        // Find max no of increasing elements (more formally, lis subsequence) on the 'left' of the element. 
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                };        
            };        
        };
        
        // Find max no of increasing elements on the 'right' of the element. 
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
*/