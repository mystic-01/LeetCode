class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        
        int i = n1 - 1, j = n2 - 1, k = n1 - 1, carry = 0;

        if (n1 > n2) {
            k = n1 - 1;
            while (i >= 0) {
                carry += num1[i] - '0';
                carry += (j >= 0) ? num2[j] - '0' : 0;
                num1[k--] = char((carry % 10) + '0');
                carry = carry / 10, i--, j--;
            };
            
            return carry ? char(carry + '0') + num1 : num1;
        } else {
            k = n2 - 1;
            while (j >= 0) {
                carry += num2[j] - '0';
                carry += (i >= 0) ? num1[i] - '0' : 0;
                
                num2[k--] = char((carry % 10) + '0');
                carry = carry / 10, i--, j--;
            };
            return carry ? char(carry + '0') + num2 : num2;
        };
    };
};