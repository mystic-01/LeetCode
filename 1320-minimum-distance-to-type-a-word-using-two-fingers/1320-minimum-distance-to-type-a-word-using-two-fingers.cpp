static const int outOfBounds = 1e7;
static const char invalidChar = char('Z' + 1);

class Solution {
public:
    int getDist(char &ch1, char &ch2, pair<int, int> *dist) {
        return abs(dist[ch1 - 'A'].first - dist[ch2 - 'A'].first) + abs(dist[ch1 - 'A'].second - dist[ch2 - 'A'].second);         
    };
    
    int minimumDistance(string word) {
        pair<int, int> dist[26];
        int n = word.size(), dp[n + 1][27][27];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 26; ++i) {
            dist[i] = {i / 6, i % 6};
        };
        for (char a = invalidChar; a >= 'A'; --a) {
            for (char b = invalidChar; b >= 'A'; --b) {
                dp[n][a - 'A'][b - 'A'] = 0;
            };
        };
        
        for (int idx = n - 1; idx >= 1; --idx) {
            for (char a = 'A'; a <= 'Z'; ++a) {
                for (char b = 'A'; b <= invalidChar; ++b) {
                    int distOne = outOfBounds, distTwo = outOfBounds; 
                    int wordIdx = word[idx] - 'A', aIdx = a - 'A', bIdx = b - 'A';

                    distOne = getDist(word[idx], a, dist) + dp[idx + 1][wordIdx][bIdx];

                    if (b == invalidChar) {
                        distTwo = 0 + dp[idx + 1][aIdx][wordIdx];
                    } else {
                        distTwo = getDist(word[idx], b, dist) + dp[idx + 1][aIdx][wordIdx];
                    };        
                    dp[idx][aIdx][bIdx] = min(distOne, distTwo);
                };
            };
            
        };
        
        return dp[1][word[0] - 'A'][invalidChar - 'A'];
    };
};