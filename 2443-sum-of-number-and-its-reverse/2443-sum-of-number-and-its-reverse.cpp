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
        for (int i = 0; i <= 1e5; i++) {
            int rev = reverse(i);
            // cout << i << " " << rev << "\n";
            if (i + rev == num) return true;            
        };                
        return false;
    };
};