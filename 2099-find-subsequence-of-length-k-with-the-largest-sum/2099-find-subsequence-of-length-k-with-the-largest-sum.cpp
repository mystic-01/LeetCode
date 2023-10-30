class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        multiset<int> ans(begin(nums), end(nums));
        vector<int> finalAns;
        auto itPlusK =  begin(ans);
        while ((int)nums.size() - k++ > 0) ++itPlusK;
        ans = multiset<int>(itPlusK, end(ans));
        for (int i = 0; i < nums.size(); ++i) {
            auto it = ans.find(nums[i]);
            if (it != ans.end()) {
                finalAns.push_back(*it);
                ans.erase(it);
            };
        };
        return finalAns;
    };
};