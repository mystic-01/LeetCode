class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, 0);
        
        for (auto i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                if (nums[st.top()] > nums[i]) {
                    ans[i] = st.top() - i;
                    break;
                } else st.pop();
            };
            st.push(i);
        };
        return ans;
    };
};