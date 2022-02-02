// class Solution {
// public:
//     bool isSubsequenceRecurse(int i, string s, int n1, int j, string t, int n2) {
//         if (i == n1) return 1;
//         if (j == n2) return 0;
//         return isSubsequenceRecurse((s[i] != t[j]) ? i : i + 1, s, n1, j + 1, t, n2);
//     };            

//     bool isSubsequence(string s, string t) {
//         return isSubsequenceRecurse(0, s, s.length(), 0, t, t.length());            
//     };
// };

class Solution {
public:
    bool isSubsequenceRecurse(int i, string s, int n1, int j, string t, int n2) {
        if (i == n1) return 1;
        if (j == n2) return 0;
        return isSubsequenceRecurse((s[i] != t[j]) ? i : i + 1, s, n1, j + 1, t, n2);
    };            

    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, n1 = s.length(), n2 = t.length();
        while (j < n2) if (s[i] == t[j++]) i++;
        return i == n1;            
    };
};