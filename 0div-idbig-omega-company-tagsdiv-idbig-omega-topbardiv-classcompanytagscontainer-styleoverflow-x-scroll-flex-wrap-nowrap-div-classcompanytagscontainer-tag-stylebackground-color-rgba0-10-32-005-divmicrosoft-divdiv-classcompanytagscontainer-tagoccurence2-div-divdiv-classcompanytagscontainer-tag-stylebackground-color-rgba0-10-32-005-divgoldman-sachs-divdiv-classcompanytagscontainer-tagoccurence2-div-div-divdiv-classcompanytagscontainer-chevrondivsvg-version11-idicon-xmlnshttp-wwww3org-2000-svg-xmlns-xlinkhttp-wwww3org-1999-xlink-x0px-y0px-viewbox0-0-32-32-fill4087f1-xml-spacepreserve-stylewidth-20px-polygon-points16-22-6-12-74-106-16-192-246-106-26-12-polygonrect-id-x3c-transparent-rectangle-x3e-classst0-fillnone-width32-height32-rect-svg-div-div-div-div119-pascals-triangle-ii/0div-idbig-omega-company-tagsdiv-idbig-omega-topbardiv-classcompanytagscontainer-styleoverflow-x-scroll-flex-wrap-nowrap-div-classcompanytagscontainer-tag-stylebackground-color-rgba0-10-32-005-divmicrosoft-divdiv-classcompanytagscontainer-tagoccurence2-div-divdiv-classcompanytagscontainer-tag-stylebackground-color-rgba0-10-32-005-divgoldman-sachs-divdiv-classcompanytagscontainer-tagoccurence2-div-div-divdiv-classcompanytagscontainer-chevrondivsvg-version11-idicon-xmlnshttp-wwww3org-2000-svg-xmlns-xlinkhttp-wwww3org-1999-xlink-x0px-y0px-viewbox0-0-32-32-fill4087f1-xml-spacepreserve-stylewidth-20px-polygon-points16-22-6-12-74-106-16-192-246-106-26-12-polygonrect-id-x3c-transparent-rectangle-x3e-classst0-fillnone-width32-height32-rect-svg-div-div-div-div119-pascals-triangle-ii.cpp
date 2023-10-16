class Solution {
public:
    vector<int> getRow(int rowIdx) {
        vector<int> ans(rowIdx + 1, 0);
        ans[0] = 1;
        for (int i = 0; i <= rowIdx; ++i) {
            for (int j = i; j > 0; --j) {
                ans[j] = ans[j] + ans[j - 1];        
            };            
        };
        return ans;
    };
};