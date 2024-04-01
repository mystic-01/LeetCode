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

        vector<int> v1 = {0}, v2 = {0};
        for (int i = 0; i < n / 2; ++i) {
            int sz = v1.size();
            for (int j = 0; j < sz; ++j) {
                v1.push_back(nums[i] + v1[j]);    
            };
        };
        for (int i = n / 2; i < n; ++i) {
            int sz = v2.size();
            for (int j = 0; j < sz; ++j) {
                v2.push_back(nums[i] + v2[j]);    
            };
        };
        
        set<int> s(begin(v2), end(v2));
        int ans = 1e9;
        for (int i = 0; i < v1.size(); ++i) {
            auto it = s.lower_bound(target - v1[i]);
            if (it != end(s)) {
                ans = min(ans, abs(target - (v1[i] + *it)));                
            };
            if (it != begin(s)) {
                --it;
                ans = min(ans, abs(target - (v1[i] + *it)));                
            };           
        };
        return ans;
    };
};
