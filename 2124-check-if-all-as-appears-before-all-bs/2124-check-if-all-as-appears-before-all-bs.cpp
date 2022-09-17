class Solution {
public:
    bool checkString(string &s) {
        bool bSeen = false;  
        for (auto &x : s) {
            if (x == 'b') bSeen = true;
            if (x == 'a' && bSeen) return false;
        };
        return true;
    };
};