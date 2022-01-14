class Solution {
public:
    int subtractProductAndSum(int n) {
        int x = n, product = 1, sum = 0;
        while (x != 0) {
            product *= x % 10;
            sum += x % 10;
            x /= 10;
        };
        
        return product - sum;
    };
};