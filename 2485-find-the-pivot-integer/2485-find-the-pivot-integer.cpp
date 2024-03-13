class Solution {
public:
    int pivotInteger(int n) {
        int digit = 1, leftSum = 1, rightSum = (n * (n + 1)) / 2;
        while (leftSum <= rightSum) {
            if (leftSum == rightSum) {
                return digit;     
            } else {
                rightSum -= digit, ++digit, leftSum += digit;    
            };
        };
        return -1;
    };
};