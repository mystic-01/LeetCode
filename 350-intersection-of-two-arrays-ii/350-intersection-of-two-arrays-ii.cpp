class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(auto &i : nums1) m[i]++;
        for(auto i = 0; i < nums2.size(); i++) if (m[nums2[i]]-- > 0) ans.push_back(nums2[i]);
        return ans;
    };
};