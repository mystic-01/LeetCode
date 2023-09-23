class Solution {
public:
    
    // Learning - When to use DP and when to use BFS.
    // Learning 2 - If you're adding letters to generate and find all possible combos, 
    // you may be able to do the same by deleting one character from a larger string.
    int longestStrChain(vector<string>& words) {
        int n = words.size(), best = 0;
        sort(words.begin(), words.end(), [](const string &str1, const string &str2) {
            return str1.size() > str2.size();    
        });
        
        unordered_map<string, bool> dict;
        queue<string> q;

        for (auto &str : words) {
            dict[str] = false;
        };
        
        for (string &x : words) {
            if (!dict[x]) {
                q.push(x);
            };
            int chain = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; ++i) {
                    string curr = q.front();
                    q.pop();
                    for (int j = 0; j < curr.size(); ++j) {
                        string dupe = curr.substr(0, j) + curr.substr(j + 1);
                        if (dict.find(dupe) != dict.end() && dict[dupe] == 0) {
                            q.push(dupe);
                            dict[dupe] = 1;
                        };
                    };
                    dict[curr] = 1;
                };
                ++chain;
            };
            best = max(chain, best);
        };
        return best;
    };
};

// n * n * l * 26
