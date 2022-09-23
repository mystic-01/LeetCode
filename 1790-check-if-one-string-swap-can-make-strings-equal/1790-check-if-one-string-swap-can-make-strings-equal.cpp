class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length(), diff = 0;
        string c1 = "", c2 = "";
        
        for (auto i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (++diff > 2) return false;
                c1 += s1[i], c2 += s2[i];    
            };
        };
        
        swap(c1[0], c1[1]);
        return c1 == c2;
    };
};