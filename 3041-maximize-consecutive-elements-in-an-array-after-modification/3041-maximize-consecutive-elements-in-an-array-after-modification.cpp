class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int maxLen = 0;
        sort(begin(nums), end(nums));
        map<int, int> m;
        for (int &x : nums) {
            m[x + 1] = m[x] + 1;
            m[x] = m[x - 1] + 1;
            maxLen = max({maxLen, m[x], m[x + 1]});
        };
        return maxLen;
    };
};