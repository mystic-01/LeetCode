class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int tSize = target.size(), idx = 0;
        for (int i = 1; i <= n && idx < tSize; ++i) {
            ops.push_back("Push");
            if (target[idx] == i) {
                ++idx;
            } else {
                ops.push_back("Pop");
            };
        };
        return ops;
    };
};