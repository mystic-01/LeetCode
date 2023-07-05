class Solution {
public:
    void recurse(int idx, string &pattern, string &ans, string &ds, bool *vis) {
        if (idx == pattern.size()) {
            ans = ans.size() ? min(ans, ds) : ds;
            return;
        };
        int lastNum = ds.back() - '0';
        
        for (int i = 1; i <= 9; i++, lastNum += (pattern[idx] == 'I' ? 1 : -1)) {
            if (lastNum >= 1 && lastNum <= 9 && !vis[lastNum]) {
                vis[lastNum] = 1;            
                ds += to_string(lastNum);
                recurse(idx + 1, pattern, ans, ds, vis);
                ds.pop_back();
                vis[lastNum] = 0;            
            };
        };
    };
    
    string smallestNumber(string pattern) {
        string ans = "", ds = "";
        bool vis[10] = {0};
        for (int i = 1; i <= 9; i++) {
            if (ans.size()) return ans;
            vis[i] = 1;
            ds += to_string(i);
            recurse(0, pattern, ans, ds, vis);
            ds.pop_back();
            vis[i] = 0;
        };
        return ans;
    };
};