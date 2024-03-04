class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        int i = 0, j = tokens.size() - 1, score = 0, bestScore = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i], ++score, ++i;
            } else if (score >= 1) {
                power += tokens[j], --score, --j;                    
            } else {
                break;
            };
            bestScore = max(score, bestScore); 
        };
        return bestScore;
    };
};