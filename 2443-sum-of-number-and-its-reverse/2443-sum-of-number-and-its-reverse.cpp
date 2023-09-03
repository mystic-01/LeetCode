// Solution 3 : On demand iterations

unordered_set<int> s;

class Solution {
public:
    Solution() {
        int digits = 1;
        for (int i = 0; i <= 1e5; i++) {
            if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) digits++; 
            s.insert(i + reverse(i, digits));            
        };          
    };
    
    int reverse(int num, int digits) {
        int ans = 0, mul = 1;
        while (num) {
            ans += ((num % 10) * pow(10, digits - 1)), num /= 10, digits--;
        };
        return ans;
    };
    
    bool sumOfNumberAndReverse(int num) {
        return s.find(num) != s.end();
    };
};