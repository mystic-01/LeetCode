class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        // These are he days I do this for!!!!
        // Hard question solved at one go, by using a custom-modified version of a brand new technique just learnt !!!
        int n = nums.size(), totSum = accumulate(begin(nums), end(nums), 0), target = totSum / 2;
        vector<pair<int, int>> v1 = {{0, 0}}, v2 = {{0, 0}};
        
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0, sz = v1.size(); j < sz; ++j) {
                v1.push_back({v1[j].first + nums[i], v1[j].second + 1});
            };        
        };
        for (int i = n / 2; i < n; ++i) {
            for (int j = 0, sz = v2.size(); j < sz; ++j) {
                v2.push_back({v2[j].first + nums[i], v2[j].second + 1});
            };        
        };        
        
        set<int> vectorOfSets[n / 2 + 1];
        for (int j = 0, sz = v2.size(); j < sz; ++j) {
            int val = v2[j].first, idx = v2[j].second;
            vectorOfSets[idx].insert(val);
        };        
        int ans = 1e9;
        for (int j = 0, sz = v1.size(); j < sz; ++j) {
            int val = v1[j].first, idx = v1[j].second, idxNeeded = n / 2 - idx;
            int searchItem = target - val;
            auto it = vectorOfSets[idxNeeded].lower_bound(searchItem);

            if (it != end(vectorOfSets[idxNeeded])) {    
                int sum = val + *it;
                ans = min(ans, abs(sum - (totSum - sum)));     
                ++it;
                if (it != end(vectorOfSets[idxNeeded])) {    
                    sum = val + *it;
                    ans = min(ans, abs(sum - (totSum - sum)));     
                };
                --it;
            };
            if (it != begin(vectorOfSets[idxNeeded])) {    
                --it;
                int sum = val + *it;
                ans = min(ans, abs(sum - (totSum - sum)));     
            };            
        };
        
        return ans;
    };
};