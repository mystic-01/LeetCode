class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), count = 0, i = 0, j = n / 2;
        
        while (i < n / 2 && j < n) {
            if (2LL * nums[i] <= nums[j]) count += 2, i++, j++;
            else j++;
        };
        
        return count;
    };
};