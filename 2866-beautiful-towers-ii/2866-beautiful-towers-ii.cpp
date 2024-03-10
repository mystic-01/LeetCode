class Solution {
public:
    void fillCost(int &n, vector<int> &nums, long long *leftCost) {
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            leftCost[i] = (i - 1 >= 0) ? leftCost[i - 1] : 0;
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int currIdx = st.top();
                st.pop();
                int nextIdx = st.empty() ? -1 : st.top();
                leftCost[i] += ((currIdx - nextIdx) * (long long)(nums[currIdx] - nums[i]));
            };    
            st.push(i);
        };        
    };
    
    long long maximumSumOfHeights(vector<int> &nums) {
        int n = nums.size();
        long long sum = accumulate(begin(nums), end(nums), 0LL);
        long long leftCost[n], rightCost[n];
        fill(leftCost, leftCost + n, 0);
        fill(rightCost, rightCost + n, 0);

        fillCost(n, nums, leftCost);
        
        reverse(begin(nums), end(nums));
        fillCost(n, nums, rightCost);    
        reverse(begin(nums), end(nums));

        reverse(rightCost, rightCost + n);

        long long minCost = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            minCost = min(minCost, leftCost[i] + rightCost[i]);
        };        
        return sum - minCost;
    };
};