class Solution {
public:
    // SPPSSSSPPS
    int numberOfWays(string corridor) {
        unordered_map<char, int> m, realCount;
        long long int plantCount = 1;
        int curr = 0, mod = 1000000007;
        for (auto i : corridor) {
            if (m['S'] == 2) {
                if (i == 'P') curr = (curr + 1) % mod;
                else {
                    m['S'] = 0;
                    plantCount = (plantCount * (curr + 1)) % mod;
                    curr = 0;
                };
            }; 
            m[i]++;
            realCount[i]++;
        };
        
        // if (realCount['S'] == 2) return 1;
        if (realCount['S'] < 2 || realCount['S'] % 2 != 0 ) return 0;
        
        return (int)plantCount;
        
    };
};