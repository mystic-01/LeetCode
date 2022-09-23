class Solution {
    
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9 + 7, i = 1;
        
        while (i <= n) {
            int len = log2(i) + 1;
            
            ans = (((ans << len) % mod) + i) % mod;

            i++;
        };        
        return (int)ans;
    };
};
