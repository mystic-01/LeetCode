class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        unordered_map<int, int> m;
        int count = 0, n = nums.size();

        for (int b = 1; b < n - 2; b++) {
            for (int a = 0; a < b; a++) m[nums[a] + nums[b]]++;
            for (int d = b + 2; d < n; d++) count += m[nums[d] - nums[b + 1]];                
        };        
        return count;
    };
};