class Solution {
public: 
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k = n - 2, i = n - 1;
        while (k >= 0)
            if (nums[k] < nums[k + 1]) break;
            else k--;
        
        if (k >= 0) {
            while (i > k) {
                if (nums[i] > nums[k]) {
                    swap(nums[i], nums[k]);
                    break;
                } else i--;
            };            
        };
        reverse(nums.begin() + k + 1, nums.end());
    };
};

// -1 3 -2 4
// sum = nums[0], best = nums[0];

// sum = max(sum + arr[i], arr[i]); -1 3 1 5
// best = max(best, sum); -1 3 1 5