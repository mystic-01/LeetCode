class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v(n + 1);
        unordered_map<int, int> m;
        vector<int> ans;
     
        for (int &i : nums) {
            m[i]++;            
        };
        for (auto &it : m) {
            v[it.second].push_back(it.first);            
        };
        for (auto i = n; i >= 0 && k; --i) {
            for (auto j = 0; j < v[i].size() && k; ++j, --k) {
                ans.push_back(v[i][j]);
            };                
        };
        return ans;
    };
};