class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int row = votes.size(), col = votes[0].size(), freq[26][26];
        unordered_set<char> available;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                freq[i][j] = 0;
            };
        };
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char ch = votes[i][j];
                ++freq[ch - 'A'][j];
                available.insert(ch);
            };        
        };
        string ans = votes[0];
        for (int i = 0; i < col; ++i) {
            char best = ' ';
            for (char ch = 'A'; ch <= 'Z'; ++ch) {
                if (available.count(ch)) {
                    if (best == ' ') {
                        best = ch;
                        available.erase(best);
                    } else {
                        int chMoreVoted = -1;
                        for (int k = 0; k < 26; ++k) {
                            if (freq[ch - 'A'][k] != freq[best - 'A'][k]) {
                                chMoreVoted = freq[ch - 'A'][k] > freq[best - 'A'][k];
                                break;
                            };
                        };    
                        if (chMoreVoted == -1) {
                            chMoreVoted = ch < best;    
                        };
                        if (chMoreVoted) {
                            available.insert(best);
                            best = ch;
                            available.erase(best);
                        };
                    };
                };
            };        
            ans[i] = best;
        };        
        return ans;
    };
};