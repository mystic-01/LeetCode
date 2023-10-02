class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), removeableA = 0, removeableB = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A') {
                if (colors[i - 1] == 'A' && colors[i + 1] == 'A') {
                    ++removeableA, colors[i - 1] = '*';                                    
                };
            } else if (colors[i] == 'B') {
                if (colors[i - 1] == 'B' && colors[i + 1] == 'B') {
                    ++removeableB, colors[i - 1] = '*';                                    
                };
            };
        };
        return removeableA > removeableB;
    };
};


/*

ABBBAAA

*/