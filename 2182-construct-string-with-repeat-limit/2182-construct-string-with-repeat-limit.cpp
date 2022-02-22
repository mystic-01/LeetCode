class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> v(26, 0);
        for (auto i : s) v[i - 'a']++;        
        
        int noVjFound = 0, it = 0;
        for (auto i = 25; i >= 0; i--) {
            int count = repeatLimit;
            while (v[i]) {
                if (noVjFound) break;
                while (v[i] && count) {
                    s[it++] = ('a' + i);
                    v[i]--, count--;
                };
                if (v[i]) {
                    count = repeatLimit, noVjFound = 1;
                    for (auto j = i - 1; j >= 0; j--) {
                        if (v[j]) {
                            s[it++] = ('a' + j), v[j]--;
                            noVjFound = 0;
                            break;
                        };
                    };
                };
            };
        };
        return s.substr(0, it);
    };
};