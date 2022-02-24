class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for (auto i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i % n] >= s.top()) s.pop();
            if (!s.empty()) ans[i % n] = s.top();
            s.push(nums[i % n]);
        };
        return ans;
    };
};