class Solution {
public:
    bool isMathOperation (char &s) {
        return (s == '/' || s == '*' || s == '+' || s == '-');         
    };
    
    string performOperation(string &s, string &op) {
        int n = s.length(), temp = 0, i = 0;
      
        string str = "", num1 = "", num2 = "";
        
        while (i < n) {
            if (s[i] == op[0] || s[i] == op[1]) {
                char currOp = s[i];
                while (++i < n && !isMathOperation(s[i])) if (s[i] != ' ') num2 += s[i];

                if (currOp == '/') temp = stoi(num1) / stoi(num2);
                else if (currOp == '*') temp = stoi(num1) * stoi(num2);
                else if (currOp == '+') temp = stoi(num1) + stoi(num2);
                else if (currOp == '-') temp = stoi(num1) - stoi(num2);
                
                num1 = to_string(temp), num2 = "";
            } else if (isMathOperation(s[i])) str += (num1 + s[i]), num1 = "", num2 = "", i++;
            else if (s[i] != ' ') num1 += s[i], i++;
            else i++;
        };
        str += num1;
        return str;
    };
    
    int calculate(string &s) {
        string op1 = "/*", op2 = "+-";
        s = performOperation(s, op1);
        s = performOperation(s, op2);

        return stoi(s);
    };
};