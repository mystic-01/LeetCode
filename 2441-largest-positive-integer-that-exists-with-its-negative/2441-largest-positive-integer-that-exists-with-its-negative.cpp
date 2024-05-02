class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_set<int> neg;
        int ans = -1;
        for (int &x : nums) {
            if (x < 0) {
                neg.insert(x);    
            } else {
                if (neg.count(-x)) {
                    ans = max(ans, x);    
                };
            };
        };
        return ans;
    };
};