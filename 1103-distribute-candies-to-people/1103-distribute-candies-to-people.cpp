class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n, 0);
        int val = 1, i = 0;
        while (candies) {
            if (candies - val >= 0) {
                candies -= val;
                ans[(i++ % n)] += val++;
            } else {
                ans[(i++ % n)] += candies;                
                candies = 0;
            };
        };
        return ans;
    };
};