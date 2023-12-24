class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), startZero = 0, startOne = 0;    
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (s[i] == '1') ++startZero;                    
                else ++startOne;
            } else {
                if (s[i] == '0') ++startZero;                    
                else ++startOne;
            };  
        };
        return min(startZero, startOne);
    };
};