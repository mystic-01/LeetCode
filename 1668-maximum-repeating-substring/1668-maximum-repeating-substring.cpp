class Solution {
public:
    int maxRepeating(string s, string word) {
        int n2 = word.length(), count = 0, best = 0, i = 0, it= 0;
        while (i < s.length()) {
            if (s.substr(i, n2) == word) {
                // cout << i << " " << s.substr(i, n2) << endl;
                count++;            
                i +=n2;
            } else {
                i = ++it;
                count = 0;
            };
            // it++;
            best = max(count, best);
            // if (it > 100) break;
        };
        return best;
    };
};