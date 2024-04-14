class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        multiset<int> ms(begin(nums), end(nums));
        int n = nums.size(), maxLeft = -1;
        for (int i = 0; i < n; ++i) {
            maxLeft = max(maxLeft, nums[i]);
            ms.erase(ms.find(nums[i]));            
            if (maxLeft <= *begin(ms)) {
                return i + 1;
            };
        };
        return -1;
    };
};