class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> ms;
        int n = nums.size(), ans = INT_MAX, xDupe = x;
        
        for (int i = x; i < n; i++) ms.insert(nums[i]);
        
        for (int i = 0; i < n - x; i++) {
            int value = nums[i];

            auto ub = ms.upper_bound(value), lb = ub;
            
            if (lb != ms.begin()) lb--;
            
            ans = min(ans, min(abs(value - *lb), abs(value - *ub)));
            ms.erase(ms.find(nums[xDupe++]));
        };
        
        return ans;
    };
};