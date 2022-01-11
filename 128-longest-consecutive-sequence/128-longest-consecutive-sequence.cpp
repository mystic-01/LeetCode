class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (nums.size() == 0) return 0;
         
        map<int, int> m;
        for (auto i = 0; i < nums.size(); i++) m[nums[i]]++;
        int count = 1, best = 1;
        auto j = m.begin(); j++;
        for (auto i = m.begin(); j != m.end(); i++) {
            if (j->first - i->first != 1) {
                best = max(best, count);
                count = 1;
            } else {
                count++;
            };
            j++;
        };
        return max(best, count);
    };
};