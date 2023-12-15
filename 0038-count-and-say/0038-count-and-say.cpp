class Solution {
public:
    string recurse(string &start) {
        if (start == "") return "1";
        string ans = "";
        char curr = start[0];
        int i = 1, count = 1;
        while (i < start.size()) {
            if (start[i] == curr) ++count; 
            else {
                ans += (to_string(count) + curr);
                curr = start[i], count = 1;
            };
            ++i;
        };            
        ans += (to_string(count) + curr);
        return ans;
    };
    
    string countAndSay(int n) {
        string ans = "";
        for (int i = 1; i <= n; ++i) {
            ans = recurse(ans);    
        };
        return ans;
    };
};