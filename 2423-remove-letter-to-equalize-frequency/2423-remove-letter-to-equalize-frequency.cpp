class Solution {
public:
    bool canMakeEqualFreq(int currFreq, int *freq) {
        int deletions = 0, nonZero = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                if (freq[i] >= currFreq) deletions += (freq[i] - currFreq);
                else deletions += freq[i]; 
                nonZero++;
            };
        };
        if (deletions == 0) {
            return (currFreq == 1) ? true : (nonZero == 1);
        };
        return deletions == 1;        
    };
    
    bool equalFrequency(string word) {
        int freq[26] = {0};
        for (char &x : word) freq[x - 'a']++;
        
        bool ans = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) ans = ans || canMakeEqualFreq(freq[i], freq);
        };
        return ans;
    };
};
