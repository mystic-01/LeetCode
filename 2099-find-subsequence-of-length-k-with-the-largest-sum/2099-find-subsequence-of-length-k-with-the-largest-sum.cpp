class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans = nums, finalAns;
        sort(ans.begin(), ans.end());
        ans = vector<int>(ans.begin() + ans.size() - k, ans.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            auto it = find(begin(ans), end(ans), nums[i]);
            if (it != ans.end()) {
                finalAns.push_back(*it);
                ans.erase(it);
            };
        };
        return finalAns;
    };
};