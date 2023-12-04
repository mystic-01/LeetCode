class Solution {
public:
    string largestGoodInteger(string num) {
        string str = "";
        int ans = -1;
        for (int i = 2; i < num.size(); ++i) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                ans = max(ans, num[i] - '0');       
            };    
        };
        if (ans != -1) str = str + char('0' + ans) + char('0' + ans) + char('0' + ans);
        return str;
    };
};