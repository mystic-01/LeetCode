class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), best = 0;
        
        auto comp = [](const string &string1, const string &string2) {
            return string1.size() < string2.size();    
        };
        sort(words.begin(), words.end(), comp);
        
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
                    for (int j = 0; j <= curr.size(); ++j) {
                        for (char c = 'a'; c <= 'z'; ++c) {
                            string dupe = curr.substr(0, j) + c + curr.substr(j);
                            if (dict.find(dupe) != dict.end() && dict[dupe] == 0) {
                                q.push(dupe);
                                dict[dupe] = 1;
                            };
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
