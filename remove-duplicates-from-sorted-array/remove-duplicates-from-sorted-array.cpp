class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == 0) {
                m[nums[i]]++;
                result.push_back(nums[i]);
            };
        };
        nums = result;
        return nums.size();
    };
};