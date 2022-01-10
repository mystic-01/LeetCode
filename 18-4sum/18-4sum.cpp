class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        vector<vector<int>> quad;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1, i = 0;
        
        while(i < n) {
            int a = nums[i], j = i + 1;
            while(j < n - 1) {
                int b = nums[j], lo = j + 1, hi = n;
                while(lo < hi) {
                    int c = nums[lo], d = nums[hi];
                    if (target - c - d == a + b) {
                        quad.push_back({a, b, c, d});
                        while (nums[lo] == c && lo < n) lo++;
                        while (nums[hi] == d && hi > 0) hi--;
                    } 
                    else if (target - c - d > a + b) while (nums[lo] == c && lo < n) lo++;
                    else while (nums[hi] == d && hi > 0) hi--;
                };
                while (nums[j] == b && j < n) j++;
            };
            while (nums[i] == a && i < n) i++;
        }; 
        return quad;
    };
};