class Solution {
public:
    string reverseStr(string s, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    
        int i = 0, j = 1, poi = 0, n = s.length();
        for (i = 0; i < n; i++) {
            if (j % (2 * k) == 0) {
                reverse(s.begin() + poi, s.begin() + poi + k);
                poi = j;
            };
            j++;
        };
        if (n - poi >= k) {
            reverse(s.begin() + poi, s.begin() + poi + k);
        } else {
            reverse(s.begin() + poi, s.end());            
        }
        return s;
    };
};