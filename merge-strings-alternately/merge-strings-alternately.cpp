class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.length(), w2 = word2.length();
        int biggerSize = (w1 > w2) ? w1 : w2;
        string answer = "";
        for (int i = 0; i < biggerSize; i++) {
            if (i < w1) answer = answer + word1.substr(i, 1);            
            if (i < w2) answer = answer + word2.substr(i, 1);
        };
        return answer;
    };
};