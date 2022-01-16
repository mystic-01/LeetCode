class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int n = a.length() - 1, m = b.length() - 1, c = 0;

        while (n >= 0 && m >= 0) {
            if (a[n] == b[m]) {
                s = to_string(c) + s;
                c = a[n] == '1' ? 1 : 0;
            } else {
                s = to_string(c == 1 ? 0 : 1) + s;
            }
            n--; 
            m--;
        };
        while (n >= 0) {
            s = to_string(a[n] == '1' && c == 1 ? 0 : c + (a[n] - 48)) + s;
            c = a[n--] == '1' && c == 1 ? 1 : 0;
        };
        while (m >= 0) {
            s = to_string(b[m] == '1' && c == 1 ? 0 : c + (b[m] - 48)) + s;
            c = b[m--] == '1' && c == 1 ? 1 : 0;
        };
        return (c == 1) ? to_string(1) + s : s;
    };
};