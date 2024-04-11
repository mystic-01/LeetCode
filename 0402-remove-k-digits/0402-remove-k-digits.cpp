class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size(), kLeft = k;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            int it = ans.size() - 1;
            if (ans.size() && ans[it] > nums[i]) {    
                while (ans.size() && kLeft && ans[it] > nums[i]) {
                    ans.pop_back();
                    --it, --kLeft;
                };
            };
            ans += nums[i];
        };
        int zeroCount = 0;
        for (int i = 0, left = 0; i < ans.size(); ++i) {
            if (ans[i] == '0') {
                ++zeroCount;
            } else {
                break;
            };
        };
        return n - k - zeroCount <= 0 ? "0" : ans.substr(zeroCount, n - k - zeroCount);
    };
};

