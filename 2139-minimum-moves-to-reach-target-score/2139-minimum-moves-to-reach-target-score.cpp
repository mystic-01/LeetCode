class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (target != 1) {
            if (target % 2 == 0 && maxDoubles) target /= 2, maxDoubles--;
            else target--;
            moves++;
            if (!maxDoubles) moves += (target - 1), target = 1;
        };      
        return moves;
    };
};