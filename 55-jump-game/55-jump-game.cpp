class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        if (n == 1) return true;
        for (auto i = 0; i < n; i++) {
            if (i == n - 1) return true;
            if (nums[i]) m[nums[i] + i]++;
            else {
                bool canNotJump = true;
                for (auto x : m) {
                    if (x.first > i) {
                        canNotJump = false;
                        x.second--;
                        break;
                    };
                };
                if (canNotJump) return false;
            };
        };
        return true;
    };
};