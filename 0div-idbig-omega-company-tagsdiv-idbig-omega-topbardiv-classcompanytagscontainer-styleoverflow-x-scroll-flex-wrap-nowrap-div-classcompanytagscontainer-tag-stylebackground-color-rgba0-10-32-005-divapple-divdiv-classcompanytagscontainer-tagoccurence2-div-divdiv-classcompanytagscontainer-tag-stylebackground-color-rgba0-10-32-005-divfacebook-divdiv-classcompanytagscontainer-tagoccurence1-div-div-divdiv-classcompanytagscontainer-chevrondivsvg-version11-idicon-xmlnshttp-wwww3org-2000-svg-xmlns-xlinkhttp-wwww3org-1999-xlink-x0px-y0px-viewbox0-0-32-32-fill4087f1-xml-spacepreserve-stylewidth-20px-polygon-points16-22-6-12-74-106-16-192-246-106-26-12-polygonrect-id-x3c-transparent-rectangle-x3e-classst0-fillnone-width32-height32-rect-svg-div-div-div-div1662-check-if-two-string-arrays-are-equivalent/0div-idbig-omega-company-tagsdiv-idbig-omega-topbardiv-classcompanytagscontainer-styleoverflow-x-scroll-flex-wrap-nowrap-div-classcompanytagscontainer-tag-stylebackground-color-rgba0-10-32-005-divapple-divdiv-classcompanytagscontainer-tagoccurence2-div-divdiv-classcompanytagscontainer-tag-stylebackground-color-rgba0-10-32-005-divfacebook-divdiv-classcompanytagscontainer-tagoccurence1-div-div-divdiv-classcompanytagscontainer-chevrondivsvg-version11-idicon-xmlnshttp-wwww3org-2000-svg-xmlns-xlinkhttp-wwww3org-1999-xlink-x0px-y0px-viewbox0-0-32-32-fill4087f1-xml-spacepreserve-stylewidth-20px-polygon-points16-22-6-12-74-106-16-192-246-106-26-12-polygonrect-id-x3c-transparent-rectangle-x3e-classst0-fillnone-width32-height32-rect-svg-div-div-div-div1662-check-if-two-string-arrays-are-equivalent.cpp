class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, n1 = word1.size(), idx1  = 0, j = 0, n2 = word2.size(), idx2  = 0;
        while (i < n1 && j < n2) {
            if (idx1 == word1[i].size()) {
                ++i, idx1 = 0;
            } else if (idx2 == word2[j].size()) {
                ++j, idx2 = 0;
            } else if (word1[i][idx1] != word2[j][idx2]) {
                return false;                
            } else {
                ++idx1, ++idx2;
            };
        };
        return ((i == n1 && idx1 == 0) || (i == n1 - 1 && idx1 == word1[i].size())) && 
            ((j == n2 && idx2 == 0) || (j == n2 - 1 && idx2 == word2[j].size()));
    };  
};