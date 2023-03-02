class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (auto &i : nums) if (i < 0) neg++; else if (i == 0) return 0;
        return neg % 2 ? -1 : 1;
    };
};