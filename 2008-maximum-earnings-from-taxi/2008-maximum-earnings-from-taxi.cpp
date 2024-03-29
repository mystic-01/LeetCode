class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides), end(rides));
        int sz = rides.size();
        long long maxProfit = 0;
        multiset<int> ms;
        unordered_map<int, long long> maxTillHereMap;
        
        long long maxSoloProfitYet = 0;
        
        for (int i = sz - 1; i >= 0; --i) {
            int start = rides[i][0], ending = rides[i][1], tip = rides[i][2];
            long long curr = ending - start + tip;
        
            auto it = ms.lower_bound(ending);
            if (it != ms.end()) {
                curr += maxTillHereMap[*it];
            };
            maxSoloProfitYet = max(maxSoloProfitYet, curr);
            
            maxTillHereMap[start] = maxSoloProfitYet;
            ms.insert(start);

            maxProfit = max(maxProfit, curr);
        };
        return maxProfit;
    };
};