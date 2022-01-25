class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> m;
        vector<int> ans;
        int i = 0;
        for (; i < nums.size(); i++) {
            if (i >= k) {
                ans.push_back(m.rbegin() ->first);
                if (m[nums[i - k]] == 1) m.erase(nums[i - k]);
                else m[nums[i - k]]--;
            };
            m[nums[i]]++;
        };
        if (i >= k) ans.push_back(m.rbegin() ->first);
        return ans;
    };
};