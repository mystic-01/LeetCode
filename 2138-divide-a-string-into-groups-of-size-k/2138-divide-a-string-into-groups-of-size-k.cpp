class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size(), size = ceil(n / (double)k);
        vector<string> ans(size);
        for (int i = 0, idx = 0; i < size; ++i, idx += k) {
            ans[i] = s.substr(idx, k);
        };
        while (ans.back().size() < k) {
            ans.back() += fill;    
        };
        return ans;
    };
};