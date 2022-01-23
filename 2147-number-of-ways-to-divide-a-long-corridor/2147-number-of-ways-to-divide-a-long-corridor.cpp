class Solution {
public:
    int numberOfWays(string corridor) {
        int curr = 0, seats = 0, plants = 0;
        long long int total = 1;
        
        for (auto i : corridor) {
            if (curr == 2) {
                if (i == 'P') plants++;
                else {
                    total = (total * (plants + 1)) % 1000000007;
                    curr = plants = 0;
                };
            }; 
            if (i == 'S') {
                curr++;
                seats++;
            };
        };
        return seats < 2 || seats % 2 != 0 ? 0 : (int) total;
        
    };
};