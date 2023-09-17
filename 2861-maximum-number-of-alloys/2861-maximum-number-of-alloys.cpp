class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxUnits = 0;
        for (auto &compo : composition) {
            int lo = 0, hi = 1e9;
            while (lo <= hi) {
                int mid = (hi - lo) / 2 + lo;
                long dupeBudget = budget;
                // try to  make mid units
                for (int i = 0; i < n; i++) {
                    long req = mid * (long)compo[i];
                    if (stock[i] < req) dupeBudget -= ((req - stock[i]) * (long)cost[i]);
                    if (dupeBudget < 0) break;
                };
                if (dupeBudget >= 0) lo = mid + 1, maxUnits = max(maxUnits, mid);
                else hi = mid - 1;
            };
        };
        return maxUnits;
    };
};