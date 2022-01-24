class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        int n = s.length(), best = 0, count = 0, i = 0;
        unordered_map<char, int> m;
        
        for (auto j = 0; j < n; j++) {
            m[s[j]]++;
            if (m.find(s[j])->second >= 2) {
                cout << "OK";
                best = max(best, count);
                while (i < n && s[i] != s[j]) m[s[i++]]--;
                m[s[i++]]--;
                count = j - i;
            };
            count++;
        };  
        best = max(best, count);

        return best;
    };
};
