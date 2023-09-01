class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int i = 0;
        
        while (i <= n) {
            int ones = 0, dupe = i;
            
            while (dupe) ones += (dupe % 2), dupe /= 2;
            ans[i] = ones;
            
            i++;
        };
        
        return ans;
    };
};