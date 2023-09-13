class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), candies[n], tots = 0;
        for (int i = 0; i < n; i++) {
            candies[i] = 1;
        };
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;                            
            };
        };
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);                            
            };
        };
        for (int i = n - 1; i >= 0; i--) {
            tots += candies[i];
        };
        return tots;
    };
};

/*

[1,2,2,2,3,4,5,6,5,5]
 1 2 1 1 2 3 4 5 2 1
 
 10 3 2 1 1 1 0 0 9
 4  3 2 1 1 2 1 1 2 
 

*/