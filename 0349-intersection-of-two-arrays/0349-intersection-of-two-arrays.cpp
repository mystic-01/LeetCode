class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int &num : nums1) {
            m[num] = 1;    
        };
        for (int &x : nums2) {
            if (m.find(x) != m.end() && ++m[x] == 2) {
                ans.push_back(x);        
            };
        };
        return ans;
    };
};