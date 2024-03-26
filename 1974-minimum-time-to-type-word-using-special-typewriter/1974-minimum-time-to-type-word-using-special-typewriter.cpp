class Solution {
public:
    int getDist(char &ch1, char &ch2) {
        return min({abs(ch1 - ch2), abs(ch1 + 26 - ch2), abs(ch1 - 26 - ch2)});         
    };
    int minTimeToType(string word) {
        int n = word.size(), moves = n;
        char curr = 'a';
        for (int i = 0; i < n; ++i) {
            moves += getDist(curr, word[i]), curr = word[i];                
        };
        return moves;
    };
};