class Solution {
public:
    string pushDominoes(string &dominos) {
        int n = dominos.size(), left = 0, right = 0;
        vector<int> leftEffect(n, 0), rightEffect(n, 0);        
        
        for (auto i = 0; i < n; i++) {
            if (dominos[i] == 'L') leftEffect[i] = 1, right = 0;     
            else if (dominos[i] == 'R') rightEffect[i] = 1, right = 1;     
            else if (right) rightEffect[i] = ++right;     
        };
        
        for (auto i = n - 1; i >= 0; i--) {
            if (dominos[i] == 'R') rightEffect[i] = 1, left = 0;     
            else if (dominos[i] == 'L') leftEffect[i] = 1, left = 1;     
            else if (left) leftEffect[i] = ++left;     
            
            if (rightEffect[i] < leftEffect[i]) dominos[i] = rightEffect[i] ? 'R' : 'L';
            else if (leftEffect[i] < rightEffect[i]) dominos[i] = leftEffect[i] ? 'L' : 'R';
            else dominos[i] = '.';
        };
        
        return dominos;
    };
};