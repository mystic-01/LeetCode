static const int outOfBounds = 1e7;
static const char invalidChar = char('Z' + 1);

class Solution {
public:
    int getDist(char &ch1, char &ch2, pair<int, int> *dist) {
        return abs(dist[ch1 - 'A'].first - dist[ch2 - 'A'].first) + abs(dist[ch1 - 'A'].second - dist[ch2 - 'A'].second);         
    };
    
    int recurse(int idx, char a, char b, pair<int, int> *dist, string &word, int (*dp)[27][27]) { 
        if (idx == word.size()) {
            return 0;    
        };
        if (dp[idx][a - 'A'][b - 'A'] != -1) {
            return dp[idx][a - 'A'][b - 'A'];    
        };
        
        int distOne = outOfBounds, distTwo = outOfBounds; 
        
        distOne = getDist(word[idx], a, dist) + recurse(idx + 1, word[idx], b, dist, word, dp);            
        
        if (b == invalidChar) {
            distTwo = 0 + recurse(idx + 1, a, word[idx], dist, word, dp);
        } else {
            distTwo = getDist(word[idx], b, dist) + recurse(idx + 1, a, word[idx], dist, word, dp);            
        };        
        return dp[idx][a - 'A'][b - 'A'] = min(distOne, distTwo);
    };
    
    int minimumDistance(string word) {
        pair<int, int> dist[26];
        int n = word.size(), dp[n + 1][27][27];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 26; ++i) {
            dist[i] = {i / 6, i % 6};
        };
        return recurse(1, word[0], invalidChar, dist, word, dp);
    };
};