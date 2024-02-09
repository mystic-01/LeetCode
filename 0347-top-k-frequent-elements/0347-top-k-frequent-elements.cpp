class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v(n + 1);
        unordered_map<int, int> m;
        vector<int> ans;
     
        for (auto i : nums)
            m[i]++;            
        for (auto i : m)
            v[i.second].push_back(i.first);
        for (auto i = n; i > -1 && k > 0; i--) {
            for (auto j = 0; j < v[i].size(); j++) {
                ans.push_back(v[i][j]);
                if (--k == 0) break;
            };                
        };
        return ans;
    };
};