class Solution {
public:
    int getLargestRectangleInAHistogram(int *vec, int &n) {
        int i = 0, maxArea = 0;
        stack<int> st;
        while (i <= n) {
            while (!st.empty() && (i == n || vec[st.top()] > vec[i])) {
                int height = st.top() < n ? vec[st.top()] : 0;
                st.pop();
                int left = st.size() ? st.top() : -1;
                int area = (i - left - 1) * height;
                maxArea = max(area, maxArea);
            };
            st.push(i++);            
        };
        return maxArea;
    };
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), maxArea = 0;
        int points[col];
        memset(points, 0, sizeof(points));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] != '0') {
                    points[j] += (matrix[i][j] - '0');
                } else {
                    points[j] = 0;                    
                };
            };
            maxArea = max(maxArea, getLargestRectangleInAHistogram(points, col));
        };                
        return maxArea;
    };
};