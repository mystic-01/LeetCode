class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size(), minE = nums[0], maxE = nums[0];

        set<int> s;
        
        for (auto i = 0; i < n; i++) {
            if (s.size() < 3) s.insert(nums[i]);
            else break;
        };
        auto it = s.begin();
        return s.size() == 3 ? *(++it) : -1;
    };
};