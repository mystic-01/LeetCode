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
        string ans = "";
        for (int i = 0; i < col; ++i) {
            char best = ' ';
            for (int j = 0; j < 26; ++j) {
                char ch = 'A' + j;
                if (!available.count(ch)) {
                    continue;    
                };
                if (best == ' ') {
                    best = ch;
                    available.erase(best);
                } else {
                    int chMoreVoted = -1;
                    for (int k = 0; k < 26; ++k) {
                        if (freq[j][k] != freq[best - 'A'][k]) {
                            chMoreVoted = freq[j][k] > freq[best - 'A'][k];
                            break;
                        };
                    };    
                    // cout << i << " " << chMoreVoted << " " << best << "\n";
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
            ans += best;
        };        
        return ans;
    };
};