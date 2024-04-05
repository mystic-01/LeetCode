class Solution {
public:
    string makeGood(string s) {
        int n = s.size(), left = 0, right = 1;
        while (right < n) {
            bool leftUp = left >= 0 ? isupper(s[left]) : false; 
            bool rightUp = left >= 0 ? isupper(s[right]) : false; 
            if (left >= 0 && tolower(s[left]) == tolower(s[right]) && ((leftUp && !rightUp) || (!leftUp && rightUp))) {
                left = left - 1;
            } else {
                left = max(0, left + 1);
                s[left] = s[right];
            };
            ++right;
        };
        return s.substr(0, left + 1);
    };
};