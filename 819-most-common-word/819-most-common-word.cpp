class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        for (auto i : banned) m[i] = -1e7;
        
        string curr = "", ans = "";
        int maxCount = 0;
        for (auto i : paragraph) {
            if (isalpha(i)) curr += tolower(i);
            else if (curr.length()) {
                if (++m[curr] > maxCount) ans = curr, maxCount = m[curr];
                curr = "";
            };
        };
        if (curr.length() && ++m[curr] > maxCount) ans = curr;
        return ans;
    };
};