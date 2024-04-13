class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), i = 0, maxArea = 0;
        while (i <= n) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = st.top() < n ? heights[st.top()] : 0;
                st.pop();
                int left = st.size() ? st.top() : -1; 
                int area = (i - left - 1) * height;
                maxArea = max(maxArea, area); 
            };            
            st.push(i++);
        };    
        return maxArea;
    };
};