class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) m[nums[i]]++;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.size() == 0) {
                if (m[target - nums[i]] >= (target - nums[i] == nums[i] ? 2 : 1)) ans.push_back(i);
            } else if (nums[i] == target - nums[ans[0]]) {
                    ans.push_back(i);
                    break;
            };
        };
        return ans;
    };
};
