class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        vector<int> ans;
        for (auto i = 0; i < n; i++) {
            m[nums[i]]++;
            if (i >= k) if (!--m[nums[i - k]]) m.erase(nums[i - k]);
            if (i >= k - 1) ans.push_back(m.rbegin()->first);
        };
        return ans;
    };
};