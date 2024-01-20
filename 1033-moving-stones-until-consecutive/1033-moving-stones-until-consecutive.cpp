class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2);
        
        int stones[3] = {a, b, c};
        sort(stones, stones + 3);
        int diff1 = (stones[1] - stones[0] - 1), diff2 = (stones[2] - stones[1] - 1);
        
        if (diff1 == 0 && diff2 == 0) ans[0] = 0;
        else if (diff1 == 0 || diff2 == 0 || diff1 == 1 || diff2 == 1) ans[0] = 1;
        else ans[0] = 2;
        ans[1] = diff1 + diff2; 
        
        return ans;
    };
};