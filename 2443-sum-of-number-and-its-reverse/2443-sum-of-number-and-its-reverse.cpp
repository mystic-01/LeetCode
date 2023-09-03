// Solution 3 : On demand iterations

class Solution {
public:
    int reverse(int num, int digits) {
        int ans = 0, mul = 1;
        
        while (num) {
            ans += ((num % 10) * pow(10, digits - 1)), num /= 10, digits--;
        };
        
        return ans;
    };
    
    bool sumOfNumberAndReverse(int num) {
        int digits = 1;
        for (int i = 0; i <= num; i++) {
            if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) digits++; 
            if (i + reverse(i, digits) == num) return true;            
        };                
        return false;
    };
};