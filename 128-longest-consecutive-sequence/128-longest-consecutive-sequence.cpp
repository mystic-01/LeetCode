class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (nums.size() == 0) return 0;
         
        map<int, int> m;
        int count = 1, best = 1;
        for (auto &i : nums) m[i]++;

        auto i = m.begin(), j = m.begin(); j++;

        while (j != m.end()) {
            best = max(best, count);
            count = (j->first - i->first != 1) ? 1 : count + 1;
            i++;
            j++;
        };
        return max(best, count);
    };
};