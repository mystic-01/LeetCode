class Solution {
public:
    string pushDominoes(string &dominos) {
        int n = dominos.size(), effect = 0;
        vector<int> right(n, 0);        
        
        for (auto i = 0; i < n; i++) {
            if (dominos[i] == 'L') effect = 0;     
            else if (dominos[i] == 'R') right[i] = 1, effect = 1;     
            else if (effect) right[i] = ++effect;     
        };
        
        for (auto i = n - 1; i >= 0; i--) {
            if (dominos[i] == 'R') effect = 0;     
            else if (dominos[i] == 'L') effect = 1;     
            else if (effect) {
                if (++effect < right[i] || right[i] == 0) dominos[i] = 'L';
                else if (effect > right[i]) dominos[i] = 'R';
            } else if (right[i]) dominos[i] = 'R';
        };
        
        return dominos;
    };
};