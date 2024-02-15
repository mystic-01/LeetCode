class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find a decrease from back
        // from 'i', find smallest element which is greater than nums[i]
        // swap(nums[i], nums[greater]);
        // sort(begin(nums) + i, end(nums));
        
        int n = nums.size(), i = n - 1, j = n;
        while (--i >= 0) {
            if (nums[i] < nums[i + 1]) {
                break;    
            };
        };
        if (i >= 0) {
            while (--j < n) {
                if (nums[j] > nums[i]) {
                    break;
                };
            };
            swap(nums[i], nums[j]);
        };
        reverse(begin(nums) + i + 1, end(nums));
    };
};

/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

*/