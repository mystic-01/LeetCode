class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        

        int n = nums.size();
        k %= n;
        auto begin = nums.begin(), end = nums.end();
        reverse(begin, begin + n - k);
        reverse(begin + n - k, end);
        reverse(begin, end);
    };
};