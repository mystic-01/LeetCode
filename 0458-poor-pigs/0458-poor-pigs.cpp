class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int lo = 0, hi = buckets, ans = 1, turns = minutesToTest / minutesToDie;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo; // curr pigs
            if (pow(turns + 1, mid) >= buckets) {
                ans = mid, hi = mid - 1;
            } else {
                lo = mid + 1;
            };
        };
        
        return ans;
    };
};