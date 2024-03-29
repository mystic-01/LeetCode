class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides), end(rides));
        
        long long sz = rides.size(), maxProfit = 0;
        multiset<int> ms;
        unordered_map<int, long long> maxTillHereMap;
        
        for (int i = sz - 1; i >= 0; --i) {
            int start = rides[i][0], ending = rides[i][1], tip = rides[i][2];
            long long curr = ending - start + tip;
        
            auto it = ms.lower_bound(ending);
            if (it != ms.end()) {
                curr += maxTillHereMap[*it];
            };
            maxProfit = max(maxProfit, curr);
            
            maxTillHereMap[start] = maxProfit;
            ms.insert(start);
        };
        return maxProfit;
    };
};