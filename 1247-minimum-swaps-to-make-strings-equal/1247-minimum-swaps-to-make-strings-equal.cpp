class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), swaps = 0, xy = 0, yx = 0;
        
        if (n1 != n2) return -1;
        
        for (auto i = 0; i < n1; i++) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;            
            else if (s1[i] == 'y' && s2[i] == 'x') yx++;            
        };
        
        swaps += (xy / 2 + yx / 2);
        xy %= 2, yx %= 2;

        if ((xy && yx) || (!xy && !yx)) swaps += (xy + yx);
        else return -1;;
        
        return swaps;
    };
};