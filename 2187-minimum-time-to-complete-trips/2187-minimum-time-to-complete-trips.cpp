class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1, hi = 1e14;
        int n = time.size();
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long trips = 0;
            for (auto i = 0; i < n; i++) {
                trips += (mid / time[i]);    
            };
            if (trips >= totalTrips) hi = mid;
            else lo = mid + 1;
        };
        return hi;
    };
};