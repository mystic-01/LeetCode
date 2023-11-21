class Solution {
public:
    int rev(int x) {
        int reverseOfx = 0;
        while (x) {
            reverseOfx *= 10;
            reverseOfx += (x % 10);
            x /= 10;
        };
        return reverseOfx;
    };
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0, mod = 1e9 + 7;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ans = (ans + m[nums[i] - rev(nums[i])]++) % mod;           
        };
        return ans;
    };
};


// 1
// 2 - 1
// 3 - 1 + 2
// 4 - 1 + 2 + 3