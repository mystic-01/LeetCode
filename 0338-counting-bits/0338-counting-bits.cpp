class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int i = 0;
        
        while (i <= n) {
            ans[i] = ans[i / 2] + i % 2;
            i++;
        };
        
        return ans;
    };
};