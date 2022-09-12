class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int &power) {
        int n = tokens.size(), score = 0, i = 0, j = n - 1;
        
        sort(tokens.begin(), tokens.end());
        
        while (i <= j) {
            if (power >= tokens[i]) power -= tokens[i], i++, score++;
            else if (score >= 1 && i != j) power += tokens[j], j--, score--;
            else return score;
        };
        
        return score;
    };
};