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
    bool pickNotPick(int start, string &s, string &t, string &ds) {
        if (ds == s) {
            cout << ds << " >> " << s << " ";
            return true;
        };
        for (auto i = start; i < t.size(); i++) {
            ds += t[i];
            if (pickNotPick(i + 1, s, t, ds)) return true;
            ds.pop_back();
            if (pickNotPick(i + 1, s, t, ds)) return true;
        };     
        return false;
    };
    
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (auto i = 0; i < t.size(); i++) index += t[i] == s[index];
        return index == s.size();
    };
};