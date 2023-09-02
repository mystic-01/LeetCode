class Solution {
public:
    int mod = 1e9 + 7;
    
    int combinatrics(int &n, int &r) {
        int res = 1;
        for (int i = 1; i <= r; i++) {
            res = ((res * (n - r + i)) / i) % mod;     
        };
        return res;
    };
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int ans = 1, freq[26] = {0}, unique = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (++freq[s[i] - 'a'] == 1) unique++;
        };
        
        if (k > unique) return 0; 
            
    	sort(freq, freq + 26, greater<int>());

        for (int i = 0; i < k; i++) {
            ans = ((long)ans * freq[i]) % mod;
        };
        
        int n = 0, r = 0;
        for (int j = 0; j < 26; j++) {
            if (freq[j] == freq[k - 1]) {
                if (j < k) r++;
                n++;
            };                   
        };
        
        ans = ((long)ans * combinatrics(n, r)) % mod;
        return (int)ans;
    };
};

/*

"bbbaacd"
3

3 2 1 1

"aabbccddee"
2

2 2 = 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4

4
4
4
4
4'

5 4 3   2 1
3 2 1 * 2 1

10 9 8 7 6 5 4  3 2 1 
7 6 5 4 3 2 1  * 3 2 1

5C2 -> 

*/