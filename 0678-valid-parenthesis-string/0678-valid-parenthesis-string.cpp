class Solution {
public:
    // bool recurse
    void printNums(int &left, int &right, int &aestrik) {
        cout << left << " " << right << " " << aestrik << "\n";
    };
    
    bool checkValidString(string s, bool checkedOnce = false) {
        int left = 0, aestrik = 0, right = 0;
        for (char &ch : s) {
            switch (ch) {
                case '(':
                    ++left;
                    printNums(left, right, aestrik);
                    break;
                case '*':
                    ++aestrik;
                    printNums(left, right, aestrik);
                    break;
                case ')':
                    ++right;
                    if (right > left + aestrik) return false;
                    printNums(left, right, aestrik);
                    break;
            };    
        };
        cout << "----------------\n";
        printNums(left, right, aestrik);
        
        if (left > right + aestrik) return false;
        int diff = abs(left - right);
        
        printNums(diff, aestrik, diff);
        cout << "khatam testcase ----------------\n";
        
        if (diff != 0 && aestrik < abs(left - right)) return false;
        reverse(begin(s), end(s));
        for (char &ch : s) {
            switch (ch) {
                case '(':
                    ch = ')';
                    break;
                case '*':
                    break;
                case ')':
                    ch = '(';
                    break;
            };    
        };

        
        return checkedOnce || checkValidString(s, true);
    };
};