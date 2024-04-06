class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), aestriks = 0, open = 0, close = 0,  aestriksTaken = 0;
        // Seee if we're able to satify all closes
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                s[i] = '*';    
                ++aestriks;    
            } else if (s[i] == ')') {
                if (open) {
                    --open;
                } else if (aestriks) {
                    --aestriks, ++aestriksTaken;
                } else {
                    return false;
                };
            } else {
                ++open;
            };
        };
        
        // Mark opens as visited that correspond to a close
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++close;
            } else if (s[i] == '(' && close) {
                s[i] = 'X', --close;
            };
        };        
        
        // Finally see if you can combine opens and astrixes OR astrixes with astrixes 
        open = 0, aestriks = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (aestriksTaken) {
                    --aestriksTaken;
                } else if (open) {
                    --open;
                } else if (++aestriks == 2) {
                    aestriks = 0;
                };    
            } else if (s[i] == '(') {
                ++open;
            };
        };        
        return open == 0 && aestriks == 0;
    };
};