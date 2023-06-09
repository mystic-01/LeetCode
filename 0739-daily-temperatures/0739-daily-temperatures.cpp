class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        
        for (auto i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                if (st.top().first > nums[i]) {
                    ans[i] = st.top().second - i;
                    break;
                } else st.pop();
            };
            st.push({nums[i], i});
        };
        return ans;
    };
};