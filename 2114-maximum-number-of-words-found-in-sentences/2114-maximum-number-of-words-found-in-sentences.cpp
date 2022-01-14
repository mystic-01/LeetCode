class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0, best = 0;
        for (auto &i : sentences) {
            count = 0;
            for (auto &j : i) {
                if (j == ' ') count++;
            };        
            best = max(best, count);
        }; 
        return ++best;
    };
};