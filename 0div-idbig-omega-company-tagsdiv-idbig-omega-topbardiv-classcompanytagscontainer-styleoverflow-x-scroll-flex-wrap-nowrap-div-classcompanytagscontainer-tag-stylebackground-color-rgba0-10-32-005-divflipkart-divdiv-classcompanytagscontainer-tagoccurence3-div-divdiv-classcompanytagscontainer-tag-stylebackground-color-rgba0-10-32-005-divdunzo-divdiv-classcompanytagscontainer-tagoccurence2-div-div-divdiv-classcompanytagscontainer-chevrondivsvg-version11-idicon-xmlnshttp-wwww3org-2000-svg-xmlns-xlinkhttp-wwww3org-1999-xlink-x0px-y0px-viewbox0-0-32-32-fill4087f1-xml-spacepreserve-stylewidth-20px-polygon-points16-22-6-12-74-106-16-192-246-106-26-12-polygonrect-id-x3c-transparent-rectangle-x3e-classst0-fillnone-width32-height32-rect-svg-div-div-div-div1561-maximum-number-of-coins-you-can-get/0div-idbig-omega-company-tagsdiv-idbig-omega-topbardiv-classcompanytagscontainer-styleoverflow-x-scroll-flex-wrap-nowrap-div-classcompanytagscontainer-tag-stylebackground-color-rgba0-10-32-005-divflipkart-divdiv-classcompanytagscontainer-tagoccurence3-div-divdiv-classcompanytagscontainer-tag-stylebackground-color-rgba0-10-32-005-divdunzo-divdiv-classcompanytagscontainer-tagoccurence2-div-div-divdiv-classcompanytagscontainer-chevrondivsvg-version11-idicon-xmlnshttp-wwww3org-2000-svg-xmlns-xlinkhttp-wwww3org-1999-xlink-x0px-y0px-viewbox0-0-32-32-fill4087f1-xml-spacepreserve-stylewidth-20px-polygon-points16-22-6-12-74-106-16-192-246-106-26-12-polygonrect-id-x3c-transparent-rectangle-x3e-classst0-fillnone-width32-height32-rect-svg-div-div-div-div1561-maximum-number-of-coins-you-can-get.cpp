class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), maxCoins = 0, totalTurns = n / 3;
        for (int i = n - 2; totalTurns; i -= 2, --totalTurns) {
            maxCoins += piles[i];
        };
        return maxCoins;
    };
};