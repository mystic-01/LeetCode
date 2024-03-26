static const int outOfBounds = 1e7;
static const char invalidChar = char('Z' + 1);

class Solution {
public:
    int getDist(char &ch1, char &ch2, pair<int, int> *dist) {
        return abs(dist[ch1 - 'A'].first - dist[ch2 - 'A'].first) + abs(dist[ch1 - 'A'].second - dist[ch2 - 'A'].second);         
    };
    
    int minimumDistance(string word) {
        int n = word.size(), dp[27][27], prev[27][27];
        memset(dp, -1, sizeof(dp));
        memset(prev, -1, sizeof(prev));

        pair<int, int> dist[26];
        for (int i = 0; i < 26; ++i) {
            dist[i] = {i / 6, i % 6};
        };
        for (char a = invalidChar; a >= 'A'; --a) {
            for (char b = invalidChar; b >= 'A'; --b) {
                prev[a - 'A'][b - 'A'] = 0;
            };
        };
        
        for (int idx = n - 1; idx >= 1; --idx) {
            for (char a = 'A'; a <= 'Z'; ++a) {
                for (char b = 'A'; b <= invalidChar; ++b) {
                    int distOne = outOfBounds, distTwo = outOfBounds; 
                    int wordIdx = word[idx] - 'A', aIdx = a - 'A', bIdx = b - 'A';

                    distOne = getDist(word[idx], a, dist) + prev[wordIdx][bIdx];
                    distTwo = (b == invalidChar ? 0 : getDist(word[idx], b, dist)) + prev[aIdx][wordIdx];
                    
                    dp[aIdx][bIdx] = min(distOne, distTwo);
                };
            };
            for (char a = invalidChar; a >= 'A'; --a) {
                for (char b = invalidChar; b >= 'A'; --b) {
                    prev[a - 'A'][b - 'A'] = dp[a - 'A'][b - 'A'];
                };
            };            
        };
        
        return prev[word[0] - 'A'][invalidChar - 'A'];
    };
};