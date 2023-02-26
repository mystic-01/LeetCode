class Solution {
public:
    string addTwoStrings(string &num1, string &num2) {
        int n1 = num1.size(), n2 = num2.size(), i = n1 - 1, j = n2 - 1, carry = 0;
        string curr = "";
            
        while (i >= 0 && j >= 0) {
            int int1 = num1[i] - '0', int2 = num2[j] - '0', total = int1 + int2 + carry;
            curr = to_string(total % 10) + curr;
            carry = total / 10;
            i--, j--;
        };
        
        while (i >= 0) {
            int int1 = num1[i] - '0', total = int1 + carry;
            curr = to_string(total % 10) + curr;
            carry = total / 10;
            i--;
        };
        
        while (j >= 0) {
            int int2 = num2[j] - '0', total = int2 + carry;
            curr = to_string(total % 10) + curr;
            carry = total / 10;
            j--;
        };
        
        if (carry) curr = to_string(carry) + curr;
        
        return curr;
    };
    
    string multiply(string num1, string num2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        string ans = "";
        string cache[10] = {""};
        
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size(), n2 = num2.size(), carry = 0;
        
        for (auto j = n2 - 1; j >= 0; j--) {
            string curr = cache[num2[j] - '0'];
            
            if (curr == "") {
                for (auto i = n1 - 1; i >= 0; i--) {
                    int int1 = num1[i] - '0', int2 = num2[j] - '0', total = (int1 * int2) + carry;
                    curr = to_string(total % 10) + curr;
                    carry = total / 10;
                };
                if (carry) curr = to_string(carry) + curr, carry = 0;
                cache[num2[j] - '0'] = curr;
            };
            for (auto zeros = n2 - j - 1; zeros > 0; zeros--) curr += '0';
            
            ans = addTwoStrings(ans, curr);

        };

        return ans;
    };
};