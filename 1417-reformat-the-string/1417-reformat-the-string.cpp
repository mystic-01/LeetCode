class Solution {
public:
    string reformat(string s) {
        int alphas[26] = {0}, nums[10] = {0}, totAlphas = 0, totNums = 0;
        for (char &ch : s) {
            if (isalpha(ch)) {
                ++alphas[ch - 'a'], ++totAlphas;
            } else {
                ++nums[ch - '0'], ++totNums;                
            };
        };
        if (abs(totAlphas - totNums) > 1) return "";
        bool isNumsFirst = totNums > totAlphas;
        for (int i = 0, a = 0, n = 0; i < s.size(); ++i) {
            if (i % 2 != isNumsFirst) {
                // num
                while (n < 10 && nums[n] == 0) ++n;
                s[i] = char('0' + n), --nums[n];
            } else{ 
                // alpha
                while (a < 26 && alphas[a] == 0) ++a;
                s[i] = char('a' + a), --alphas[a];
            };
        };
        return s;
    };
};