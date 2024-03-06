class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), left = 0, curr = INT_MIN, count = 0;
        for (int right = 0; right < n; ++right) {
            if (curr == INT_MIN || curr != nums[right]) {
                curr = nums[right];
                count = 1;
            } else {
                ++count;              
            };
            if (count <= 2) {
                nums[left++] = curr;                        
            };              
        };
        return left;
    };
};