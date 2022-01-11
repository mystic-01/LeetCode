class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        map<int, int> m;
        int count = 0;
        for (auto &i : nums) m[i]++;
        for (auto &i : m) count += ((i.second - 1) * i.second) / 2;
        return count;
    };
};