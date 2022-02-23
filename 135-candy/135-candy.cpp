class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> candies(n, 1);
        int ans = 0;
        
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i - 1]) candies[i] = 1 + candies[i - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) candies[i] = max(candies[i], 1 + candies[i + 1]);
            ans += candies[i];
        };
        
        ans += candies[n - 1];
        return ans;
    };
};
