class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size(), idx = 0, ans = 0;
        while (idx < n) {
            while (!st.empty() && height[idx] > height[st.top()]) {
                int curr = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = idx - st.top() - 1;
                int currHeight = (min(height[idx], height[st.top()]) - height[curr]);
                int area = distance * currHeight;
                ans += area;
            };
            st.push(idx++);
        };
        return ans;
    };
};