
class Solution {
public: 
    int recurse(int idx, vector<string>& words, vector<int>& score, vector<int> &freq, map<pair<int, vector<int>>, int> &m) {
        if (idx == words.size()) return 0;
        
        if (m.find({idx, freq}) != m.end()) {
            cout << m[{idx, freq}] << "\n";
            
            return m[{idx, freq}];
        };
        
        int take = -1e7, notTake = -1e7, currScore = 0;
        bool canTake = 1; 
        for (char &ch : words[idx]) {
            if (--freq[ch - 'a'] < 0) canTake = 0;
            currScore += score[ch - 'a'];
        };                
        if (canTake) {
            // cout << "canTake - " << idx << "\n";
            take = currScore + recurse(idx + 1, words, score, freq, m);
        };
        for (char &ch2 : words[idx]) {
            ++freq[ch2 - 'a'];
        };
        // cout << idx << " : " << take << " " << notTake << "\n";
        notTake = recurse(idx + 1, words, score, freq, m);
        return m[{idx, freq}] = max(take, notTake);
    };
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<pair<int, vector<int>>, int> m;
        vector<int> freq(26, 0);
        for (char &chr : letters) {
            ++freq[chr - 'a'];
        };
        // cout << "\n";
        return recurse(0, words, score, freq, m);
    };
};