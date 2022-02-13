class Solution {
public:
    int lowerBound(int lo, int hi, vector<int> nums, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        };
        // cout << nums[hi] << " " << target << "\n";
        return nums[hi] >= target ? nums[hi] : INT_MAX;  
    };
    
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> starts(n), ans(n);
        unordered_map<int, int> m({{INT_MAX, -1}});
        
        for (auto i = 0; i < n; i++) m[nums[i][0]] = i, starts[i] = nums[i][0];
        sort(starts.begin(), starts.end());
        // for (auto i = 0; i < n; i++) cout << starts[i] << " ";

        for (auto i = 0; i < n; i++) ans[i] = m[lowerBound(0, n - 1, starts, nums[i][1])];

        return ans;
    };
};