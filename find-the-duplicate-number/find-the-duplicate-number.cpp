class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if(ans[nums[i]] == -1) return nums[i];
            ans[nums[i]] = -1;
        };
        return 0;
    };
};
  
  
  
  
  