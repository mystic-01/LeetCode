class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        
        for (int mid = 0; mid < n; ++mid) {
            int l = mid, r = mid;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++count, --l, ++r;    
            };
            l = mid, r = mid + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++count, --l, ++r;    
            };            
        };

        return count;           
    };
};
