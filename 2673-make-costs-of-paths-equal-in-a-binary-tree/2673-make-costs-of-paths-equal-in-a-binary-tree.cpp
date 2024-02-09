class Solution {
public:
    int minIncrements(int n, vector<int>& nums) {
        int inc = 0;
        
        
        for (auto i = n - 1; i >= 0; --i) {
            int diffBetweenChildren = 0;
            if (2 * i + 1 < n && 2 * i + 2 < n) {
                diffBetweenChildren = abs(nums[2 * i + 1] - nums[2 * i + 2]);                    
                nums[i] += max(nums[2 * i + 1], nums[2 * i + 2]);                    
                inc += diffBetweenChildren;
            };
        };
        
        return inc;
    };
};

//               764
//             /    \
//         1460      2664
//        /   \        /   \
//     764    2725     4556         5305
//    /  \     /  \      /  \      /    \
// 8829  5064 5929 7660 6321 4830  7055 3761
                  
//                   2664 - 1460 + (3 * 5305) - 4556 - 2725 - 764 + (7 * 8829) - 5064 - 5929 - 7660 - 6321 - 4830 - 7055 - 3761