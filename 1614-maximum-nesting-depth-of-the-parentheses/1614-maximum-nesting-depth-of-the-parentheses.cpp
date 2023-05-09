class Solution {
public:
    int maxDepth(string s) {
        int best = 0, open = 0;
        
        for (auto &ch : s) {
            if (ch == '(') open++;
            else if (ch == ')') open--;
            
            best = max(best, open);
        };
        
        return best;
    };
};