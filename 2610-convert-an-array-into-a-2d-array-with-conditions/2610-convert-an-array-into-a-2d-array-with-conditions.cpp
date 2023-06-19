class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int count[201] = {0}, maxSize = 0;        
        
        for (auto &x : nums) ++count[x], maxSize = max(maxSize, count[x]);

        vector<vector<int>> ans(maxSize);
        
        for (auto i = 0; i < 201; i++) {
            while (count[i] != 0) {
                ans[count[i] - 1].push_back(i);   
                count[i]--;
            };
        };
        return ans;
    };
};