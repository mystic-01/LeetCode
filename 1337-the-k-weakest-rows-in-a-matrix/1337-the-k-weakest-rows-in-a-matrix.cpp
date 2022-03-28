class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> m;
        vector<int> ans;
        int index = 0;
        for (auto &i : mat) 
            m[accumulate(i.begin(), i.end(), 0)].push_back(index++);
        
        for (auto &vec : m) {
            for (auto &x : vec.second) {
                if (!k) break;
                ans.push_back(x), k--;
            };
        };
        return ans;
    };
};