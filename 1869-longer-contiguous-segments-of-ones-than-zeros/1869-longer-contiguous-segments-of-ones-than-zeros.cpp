class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.length(), bestOnes = 0, currOnes = 0, bestZeros = 0, currZeros = 0;
        for (auto i = 0; i < n; i++) {
            if (s[i] == '1') currOnes++, bestZeros = max(bestZeros, currZeros), currZeros = 0;
            else currZeros++, bestOnes = max(bestOnes, currOnes), currOnes = 0;
        };
        bestZeros = max(bestZeros, currZeros), bestOnes = max(bestOnes, currOnes);
        return bestOnes > bestZeros;
    };
};