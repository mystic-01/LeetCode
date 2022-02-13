class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> starts(n);
        vector<int> ans(n);
        
        for (auto i = 0; i < n; i++) starts[i] = {nums[i][0], i};
        sort(starts.begin(), starts.end());

        for (auto i = 0; i < n; i++) {
            int lo = 0, hi = n - 1, target = nums[i][1]; 
             while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (starts[mid].first < target) lo = mid + 1;
                else hi = mid;
            };
            ans[i] = starts[hi].first >= target ? starts[hi].second : -1;
        };

        return ans;
    };
};