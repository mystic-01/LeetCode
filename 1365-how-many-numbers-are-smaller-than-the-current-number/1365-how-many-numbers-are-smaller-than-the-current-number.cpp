class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        map<int, int> m;
        int count = 0, temp = 0;
        for (auto &i : nums) m[i]++;
        for (auto &j : m) {
            temp = j.second;
            j.second = count;
            count += temp;
        };
        for (auto &k : nums) k = m[k];
        return nums;
    };

};