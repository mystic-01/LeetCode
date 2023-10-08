class Solution {
public:
    int recurse(int i, int j, vector<int>& nums1, vector<int>& nums2, int (*dp)[501]) {
        if (i >= nums1.size() || j >= nums2.size())  {
            return INT_MIN;            
        };        
        if (dp[i][j] != -1) {
            return dp[i][j];
        };
        
        int take1Take2 = INT_MIN, take1 = INT_MIN, take2 = INT_MIN;
        if (nums1[i] * nums2[j] >= 0) {
            take1Take2 = recurse(i + 1, j + 1, nums1, nums2, dp);
            take1Take2 = nums1[i] * nums2[j] + (take1Take2 == INT_MIN ? 0 : take1Take2); 
        };
        take1 = recurse(i, j + 1, nums1, nums2, dp);
        take2 = recurse(i + 1, j, nums1, nums2, dp);
    
        return dp[i][j] = max({take1, take2, take1Take2});
    };
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int min1 = *min_element(begin(nums1), end(nums1));
        int max1 = *max_element(begin(nums1), end(nums1));
        int min2 = *min_element(begin(nums2), end(nums2));
        int max2 = *max_element(begin(nums2), end(nums2));
        int ans = max({max2 * max1, min2 * min1, max2 * min1, min2 * max1});

        int dp[nums1.size()][501];
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < 501; ++j) {
                dp[i][j] = -1;
            };        
        };

        int result = recurse(0, 0, nums1, nums2, dp);
        return result == INT_MIN ? ans : result;
    };
};