class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int zero = 0, one = 0, n = nums.size() - 1;
        
        while (one <= n && n > 0) {
            swap(nums[one], nums[zero]);
            while (zero <= n && nums[zero] != 0) zero++;
            one = zero + 1;
            while (one <= n && nums[one] == 0) one++;
        };
    };
};
