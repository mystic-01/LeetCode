class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> ms;
        unordered_map<int, int> m;
        // unordered_set<int> seen;
        
        int n = nums.size(), ans = INT_MAX, xDupe = x;
        
        for (int i = x; i < n; i++) ms.insert(nums[i]), m[nums[i]]++;
        
        for (int i = 0; i < n - x; i++) {
            int value = nums[i];

            // if (!seen.count(value)) {
                // seen.insert(value);
                auto ub = ms.upper_bound(value);
                auto lb = ub;
            
                if (lb != ms.begin()) lb--;
            
                ans = min(ans, min(abs(value - *lb), abs(value - *ub)));
            // };

            if (--m[nums[xDupe]] == 0) ms.erase(nums[xDupe]);
            xDupe++;
        };
        
        return ans;
    };
};