// Think!!! You got this!
// class Solution {
// public:
//     vector<int> numsSameConsecDiff(int n, int k) {
//         // n = 9, k = 1 ->>>not working
//         vector<int> ans;
//         int minimum = pow(10, n - 1);
//         for (auto i = 0; i <= 9; i++) {
//             int num1 = 0, num2 = 0, add = 0; 
//             for (auto j = 0; j < n; j++) {
//                 if (!add) {
//                     if (num1 != INT_MIN) num1 += (pow(10, j) * i);
//                     if (num2 != INT_MIN) num2 += (pow(10, j) * i);
//                 } else {
//                     if (num1 != INT_MIN && i + k <= 9) num1 += (pow(10, j) * (i + k));
//                     else num1 = INT_MIN;
//                     if (num2 != INT_MIN && i - k >= 0) num2 += (pow(10, j) * (i - k));
//                     else num2 = INT_MIN;
//                 };
//                 add = !add;
//             };
//             if (num1 >= minimum) ans.push_back(num1);
//             if (num2 >= minimum) ans.push_back(num2);
//         };
//         return ans;
//     };
// };

class Solution {
public:
    void findValidNumbers(int last, vector<int> &ans, int &diff, int power, int ds, int &n, int &bar) {
        if (power == n) {
            if (ds >= bar) ans.push_back(ds);
            return;
        };
        if (last + diff < 10) {
            int add = ds + (pow(10, power) * (last + diff));
            findValidNumbers(last + diff, ans, diff, power + 1, add, n, bar);    
        };
        if (last - diff > -1 && diff != 0) {
            int subtract = ds + (pow(10, power) * (last - diff));
            findValidNumbers(last - diff, ans, diff, power + 1, subtract, n, bar);
        };
        return;
    };
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        int bar = pow(10, n - 1);

        for (auto i = 0; i <= 9; i++) {
            findValidNumbers(i, ans, k, 1, i, n, bar);    
        };
      
        return ans;
    };
};