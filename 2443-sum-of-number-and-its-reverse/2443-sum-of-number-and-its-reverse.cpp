// Solution 2 : Reverse Values Cached

class Solution {
private:
    int rev[100001] = {0};
public:
    Solution() {
        for (int i = 0; i <= 1e5; i++) {
            if (rev[i] == 0) rev[i] = reverse(i);
            if (rev[rev[i]] == 0) rev[rev[i]] = i;
        }; 
    };
    
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
            // cout << i << " " << rev[i] << "\n";
            if (i + rev[i] == num) return true;            
        };                
        return false;
    };
};