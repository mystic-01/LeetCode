class Solution {
public:
    int countOdds(int low, int high) {
        int digits = high - low - 1, odds = 0;
        
        if (low % 2 || high % 2) odds += (digits / 2) + (low % 2) + (high % 2);
        else odds += (digits / 2 + 1);
        
        return low == high ? low % 2 : odds;
    };
};