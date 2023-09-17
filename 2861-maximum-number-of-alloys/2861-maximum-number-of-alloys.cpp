class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxUnits = 0;
        for (auto &compo : composition) {
            int lo = 0, hi = 1e9;
            while (lo <= hi) {
                int mid = (hi - lo) / 2 + lo;
                long long dupeBudget = budget;
                // try to  make mid units
                for (int i = 0; i < n; i++) {
                    long long req = mid * 1LL * compo[i];
                    if (stock[i] < req) dupeBudget -= ((req - stock[i]) * 1LL * cost[i]);
                    // cout << req << " " << dupeBudget << " : " << mid << "\n";
                    if (dupeBudget < 0) break;
                };
                if (dupeBudget >= 0) lo = mid + 1, maxUnits = max(maxUnits, mid);
                else hi = mid - 1;
            };
        };
        return maxUnits;
    };
};

/*

4
4
17
[[10,10,1,5],[9,7,7,1],[6,3,5,9],[2,10,2,7]]
[9,8,2,7]
[9,2,6,10]
3
2
15
[[1,1,1],[1,1,10]]
[0,0,0]
[1,2,3]
3
2
15
[[1,1,1],[1,1,10]]
[0,0,100]
[1,2,3]
2
3
10
[[2,1],[1,2],[1,1]]
[1,1]
[5,5]
4
9
55
[[8,3,4,2],[3,9,5,5],[1,7,9,8],[7,6,5,1],[4,6,9,4],[6,8,7,1],[5,10,3,4],[10,1,2,4],[10,3,7,2]]
[9,1,10,0]
[3,4,9,9]

*/
