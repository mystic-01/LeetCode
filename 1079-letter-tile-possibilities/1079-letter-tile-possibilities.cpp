class Solution {
public:
    void recurse(int &unique, int *freq, int &ans) {
        ans++;
        for (int i = 0; i < unique; i++) {
            if (freq[i]) {
                freq[i]--;
                recurse(unique, freq, ans);
                freq[i]++;
            };
        };
    };
    
    int numTilePossibilities(string tiles) {
        int freq[26] = {0}, ans = 0, unique = 0;
        
        for (char &ch : tiles) freq[ch - 'A']++;
        for (int i = 0; i < 26; i++) if (freq[i]) unique++;
        
        int finalFreq[unique];
        for (int i = 0, idx = 0; i < 26; i++) if (freq[i]) finalFreq[idx++] = freq[i];      
    
        recurse(unique, finalFreq, ans);
        return ans - 1;
    };
};

/*



*/