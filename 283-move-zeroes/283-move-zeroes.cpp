class Solution {
public:
//     void moveZeroes(vector<int>& nums) {
//         std::ios::sync_with_stdio(false);
//         std::cin.tie(nullptr);
//         int zero = 0, one = 0, n = nums.size() - 1;
        
//         while (one <= n && zero <= n && n > 0) {
//             swap(nums[one], nums[zero]);
//             while (zero <= n && nums[zero] != 0) zero++;
//             one = zero + 1;
//             while (one <= n && nums[one] == 0) one++;
//         };
//     };
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zero = 0, nonZero = 0;
        while (nonZero < n) {
            while (zero < n && nums[zero] != 0) zero++;  
            nonZero = zero + 1;
            while (nonZero < n && nums[nonZero] == 0) nonZero++;     
            if (nonZero < n) swap(nums[zero], nums[nonZero]);    
        };
    };
    
};
