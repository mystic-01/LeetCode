class Solution {
public:
    int getLargestSqArea(int *nums, int &n) {
        int i = 0, maxArea = 0;
        stack<int> st;
        while (i <= n) {
            while (!st.empty() && (i == n || nums[i] < nums[st.top()])) {
                int height = nums[st.top()];
                st.pop();
                int left = st.size() ? st.top() : -1;
                int area = pow(min(i - left - 1, height), 2);
                maxArea = max(maxArea, area);
            };  
            st.push(i++);
        };
        return maxArea;
    };
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), maxArea = 0, nums[col];
        memset(nums, 0, sizeof(nums));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                nums[j] = matrix[i][j] == '0' ? 0 : nums[j] + 1;
            };        
            int area = getLargestSqArea(nums, col);
            maxArea = max(maxArea, area);
        };
        return maxArea;
    };
};