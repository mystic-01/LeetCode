class Solution {
public:   
    int minAbsDifference(vector<int>& nums, int target) {
        int n = nums.size(), maxSum = 0, minSum = 0;
        for (int &x : nums) {
            if (x > 0) {
                maxSum += x;
            } else {
                minSum += x;                
            };
        };
        if (target >= maxSum || target <= minSum) {
            return min(abs(target - maxSum), abs(target - minSum));            
        };
        // Create list of all possible sums using power-set algo
        vector<int> v1 = {0}, v2 = {0};
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0, sz = v1.size(); j < sz; ++j) {
                v1.push_back(nums[i] + v1[j]);    
            };
        };
        for (int i = n / 2; i < n; ++i) {
            for (int j = 0, sz = v2.size(); j < sz; ++j) {
                v2.push_back(nums[i] + v2[j]);    
            };
        };
        // Check if any of the sums found produce the smallest diif with the target
        int ans = 1e9;
        for (int i = 0; i < v1.size(); ++i) {
            ans = min(ans, abs(target - v1[i]));
        };
        for (int i = 0; i < v2.size(); ++i) {
            ans = min(ans, abs(target - v2[i]));
        };        
        // Two sum with 'l' pointer on left of first vector and 'r' pointer on right of second vector
        // works exactly like a normal two sum now
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));
        int l = 0, r = v2.size() - 1;
        while (l <= v1.size() - 1 && r >= 0) {
            int sum = v1[l] + v2[r];
            ans = min(ans, abs(target - sum));
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                return 0;
            };
        };
        return ans;
    };
};
