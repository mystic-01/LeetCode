class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> arr(101);
        int ans = 0;
        for (auto i : nums) arr[i]++;
        for (auto j = 1; j <= 100; ++j) if (arr[j] == 1) ans += j;
        return ans;
    };
};