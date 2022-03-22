class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        int i;
        for(i = 0; i < n; i++) ans += 'a';
        k -= n, i = n - 1;
        while(k > 0 && i >= 0){
            if(k >= 25) ans[i] = 'z', k -= 25;
            else ans[i] += char(k), k = 0;
            i--;            
        }
        return ans;       
    }
};