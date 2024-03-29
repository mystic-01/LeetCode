class Solution {
public:
    int binarySearch(int &start, int &sz, int &target, vector<vector<int>>& rides) {
        int lo = start, hi = sz - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (rides[mid][0] < target) {
                lo = mid + 1;
            } else if (rides[mid][0] > target) {
                hi = mid - 1;                
            } else {
                return mid;
            };
        };
        if (rides[hi][0] < target) {
            ++hi;
        };
        return hi;
    };
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides), end(rides));
        int sz = rides.size();
        long long maxProfit = 0, maxTillHereMap[n + 1];

        for (int i = sz - 1; i >= 0; --i) {
            int start = rides[i][0], ending = rides[i][1], tip = rides[i][2];
            long long curr = ending - start + tip;
        
            int idx = binarySearch(i, sz, ending, rides);
            if (idx != sz) {
                curr += maxTillHereMap[rides[idx][0]];
            };
            if (curr > maxProfit) {
                maxProfit = curr;            
            };
            maxTillHereMap[start] = maxProfit;
        };
        return maxProfit;
    };
};