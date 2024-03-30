class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> s;
        for (int i = 0; i < n; ++i) {
            vector<int> sub;
            for (int j = i, divi = 0; j < n; ++j) {
                if (nums[j] % p == 0) {
                    ++divi;
                };
                if (divi <= k) {
                    sub.push_back(nums[j]);
                    s.insert(sub);
                };
            };        
        };
        return s.size();
    };
};