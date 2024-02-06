class Solution {
public:
    string getPermutation(int n, int k) {
        string kthPermutation = "";

        vector<char> chars(n, '1');
        for (int i = 1; i < n; ++i) {
            chars[i] = chars[i - 1] + 1;
        };
        
        int fact[n + 1];
        fact[0] = 1, k--;
        for (int i = 1; i < n + 1; ++i) {
            fact[i] = i * fact[i - 1];    
        };
    
        int nDupe = n;
        while (kthPermutation.size() < n) {
            int currIdx = k / fact[--nDupe];
            kthPermutation = kthPermutation + chars[currIdx];
            auto it = begin(chars) + currIdx;
            chars.erase(it);
            k %= fact[nDupe];
        };
        return kthPermutation;
    };
};