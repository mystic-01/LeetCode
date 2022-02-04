class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int n = nums.size(), zeroCount = 0, oneCount = 0, best = 0;
        for (auto i = 0; i < n; i++) {
            if (nums[i]) oneCount++;
            else zeroCount++;
            
            int diff = oneCount - zeroCount;
            
            if (m.find(diff) != m.end()) best = max(best, i - m[diff]);
            else m[diff] = i;
        };
        return best;
    };
};