class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();        
        int i = n1 - 1, j = n2 - 1, carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i] - '0';
            if (j >= 0) sum += num2[j] - '0';
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
            i--, j--;
        };
        return ans;
    };
};