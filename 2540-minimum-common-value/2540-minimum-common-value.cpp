class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, pair<bool, bool>> m;
        for (auto &k : nums1) m[k].first = true;
        for (auto &j : nums2) m[j].second = true;
        for (auto &i : m) if (i.second.second && i.second.first) return i.first;
        return -1;
    };
};