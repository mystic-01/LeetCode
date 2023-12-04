class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> ones;
        set<int> zeros;
        vector<int> ans(n, 1);
        
        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                ans[i] = -1;
                if (ones.find(rains[i]) == ones.end()) {
                    ones[rains[i]] = i;    
                } else {
                    auto lb = zeros.lower_bound(ones[rains[i]]);
                    if (zeros.size() && lb != zeros.end()) {
                        ans[*lb] = rains[i];
                        ones[rains[i]] = i;
                        zeros.erase(lb);
                    } else return {};
                };
            } else zeros.insert(i);    
        };
        return ans;
    };
};