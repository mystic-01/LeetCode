// Solution 3 : On demand iterations

class Solution {
public:
    int reverse(int num) {
        int ans = 0, digits = 0, mul = 1;
        
        while (num / mul > 0) {
            mul *= 10, digits++;
        };
        while (num) {
            ans += ((num % 10) * pow(10, digits - 1)), num /= 10, digits--;
        };
        
        return ans;
    };
    
    bool sumOfNumberAndReverse(int num) {

        for (int i = 0; i <= num; i++) {
            if (i + reverse(i) == num) return true;            
        };                
        return false;
    };
};