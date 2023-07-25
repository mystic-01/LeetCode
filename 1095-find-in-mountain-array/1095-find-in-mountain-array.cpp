class Solution {
public:
    int binarySearch(int &lo, int &hi, int &target, MountainArray &mountainArr, map<int, int> &m, bool incresingArray) {
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (m.find(mid) == m.end()) m[mid] = mountainArr.get(mid);    
            
            if (m[mid] < target) {
                if (incresingArray) lo = mid + 1; 
                else hi = mid - 1;;
            } else if (m[mid] > target) {
                if (incresingArray) hi = mid - 1; 
                else lo = mid + 1;
            } else return mid;
        };
        return -1;
    };
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), peak = 0, lo = 0, hi = n - 1;
        map<int, int> m;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (m.find(mid) == m.end()) m[mid] = mountainArr.get(mid);    
            if (m.find(mid + 1) == m.end()) m[mid + 1] = mountainArr.get(mid + 1);    
                
            if (m[mid] < m[mid + 1]) lo = mid + 1;
            else {
                if (m.find(mid - 1) == m.end()) m[mid - 1] = mountainArr.get(mid - 1);    
                if (m[mid] < m[mid - 1]) hi = mid - 1;
                else {
                    peak = mid;
                    break;
                };
            };
        };

        lo = 0, hi = peak;
        int ans = binarySearch(lo, hi, target, mountainArr, m, true);
        if (ans != -1) return ans;

        lo = peak + 1, hi = n - 1;        
        ans = binarySearch(lo, hi, target, mountainArr, m, false);        
        return ans;
    };
};

