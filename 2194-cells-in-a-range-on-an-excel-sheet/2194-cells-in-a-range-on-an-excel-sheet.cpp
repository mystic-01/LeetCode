class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        int i = 0;
        for (char ch = s[0]; ch <= s[3]; ++ch) {
            for (char num = s[1]; num <= s[4]; ++num) {
                string str = "";
                str += char(ch);
                str += char(num);
                ans.push_back(str);
            };        
        };
        return ans;
    };
};