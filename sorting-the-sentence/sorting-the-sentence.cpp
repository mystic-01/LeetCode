class Solution {
public:
    string sortSentence(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        s += " ";
        string ans;
        map<int, string> m;
        auto prev = 0;
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                m[int(s[i-1])] = s.substr(prev, i-1-prev);
                prev = i + 1;
            };
        };
        for (auto i : m){
          ans= ans + i.second + " ";
        };
        return ans.substr(0, ans.length() - 1);
    };
};