class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> s;
        vector<int> ans;
        for (auto i = 0; i < n; i++) {
            s.insert(nums[i]);
            if (i >= k) s.erase(s.find(nums[i - k]));
            if (i >= k - 1) ans.push_back(*s.rbegin());
        };
        return ans;
    };
};