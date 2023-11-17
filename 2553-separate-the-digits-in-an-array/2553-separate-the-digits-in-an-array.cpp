class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int idx = 0;
        for (int &x : nums) {
            idx = ans.size();
            while (x) {
                ans.push_back(x % 10);
                x /= 10;
            };
            reverse(ans.begin() + idx, ans.end());
        };
        return ans;
    };
};