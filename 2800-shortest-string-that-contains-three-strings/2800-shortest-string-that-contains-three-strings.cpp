class Solution {
public:
    string joinTwoStrings(string &a, string &b) {
        int len1 = a.size(), len2 = b.size();
        
        for (int i = 0; i < len1; i++) {
            if (a[i] == b[0]) {
                int tempI = i + 1, tempJ = 1;
                while (tempI < len1 && tempJ < len2 && a[tempI] == b[tempJ]) tempI++, tempJ++;         
                if (tempI == len1) return a.substr(0, i) + b;
                else if (tempJ == len2) return a;
            };            
        };
        return a + b;
    };
    
    
    string minimumString(string a, string b, string c) {
        string ab = joinTwoStrings(a, b);
        string ac = joinTwoStrings(a, c);
        string ba = joinTwoStrings(b, a);
        string ca = joinTwoStrings(c, a);
        
        string arr[6];
        arr[0] = joinTwoStrings(ab, c);
        arr[1] = joinTwoStrings(ac, b);
        arr[2] = joinTwoStrings(ba, c);
        arr[3] = joinTwoStrings(b, ca);
        arr[4] = joinTwoStrings(ca, b);
        arr[5] = joinTwoStrings(c, ba);

        string ans = arr[0];                
        for (int i = 1; i < 6; i++) {
            if (arr[i].size() < ans.size()) ans = arr[i];
            else if (arr[i].size() == ans.size()) ans = min(ans, arr[i]);
        };
        
    
        return ans;
    };
};