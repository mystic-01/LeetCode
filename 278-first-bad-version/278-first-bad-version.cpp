// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int lowerBound (int lo, int hi) {
        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        };
        return hi;
    };
    
    int firstBadVersion(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);  
        return lowerBound(1, n);
    };
};