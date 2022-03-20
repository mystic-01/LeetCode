class Solution {
public:
    // Fund the mistake!!!!!!
    int minDominoRotations(vector<int>& tops, vector<int>& bots) {
        int n = tops.size(), top = tops[0], bot = bots[0], top1 = 0, bot1 = 0, top2 = 0, bot2 = 0;
        for (auto i = 0; i < n; i++) {
            // if ((tops[i] != top && tops[i] != bot) || (bots[i] != bot && bots[i] != top)) return -1; 
            if (tops[i] != top && bots[i] != top) top = 0;
            if (tops[i] != bot && bots[i] != bot) bot = 0;
            top1 += tops[i] == top; 
            bot1 += bots[i] == bot;
            top2 += bots[i] == top;
            bot2 += tops[i] == bot;            
           
        };
        return top || bot ? min(min(n - top1, n - top2), min(n - bot1, n - bot2)) : -1; 
    };
};