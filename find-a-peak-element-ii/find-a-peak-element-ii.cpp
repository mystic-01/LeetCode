class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        for (auto i = 0; i < mat.size(); i++) {
            auto begin = mat[i].begin(), end = mat[i].end();
            int element = *max_element(begin, end), j = find(begin, end, element) - begin;
            if ((i+1 == mat.size() || element > mat[i+1][j]) && 
                (i-1 < 0 || element > mat[i-1][j])) {
                vector<int> ans = {i, j};
                return ans;
            };
        };
        return {0, 0};
    };
};