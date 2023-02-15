class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size(), carry = 0;
        for (auto i = n - 1; i >= 0; i--) {
            int num = nums[i] + (k % 10) + carry;
            k /= 10, carry = num / 10, nums[i] = num % 10;            
        };
        
        if (k + carry) {
            // reverse(nums.begin(), nums.end());
            while (k + carry) {
                int num = (k % 10) + carry;
                k /= 10, carry = num / 10;
                nums.insert(nums.begin(), num % 10);
            };
            // reverse(nums.begin(), nums.end());
        };
        
        return nums;
    };
};