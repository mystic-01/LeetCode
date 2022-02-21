class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (auto i : nums) {
            if (count == 0) candidate = i;
            count += (candidate == i) ? 1 : -1;
        };
        return candidate;
    };
};