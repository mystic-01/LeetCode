class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size(), sum = accumulate(begin(machines), end(machines), 0); 
        int sumPerMachine = sum / n, moves = 0, left = 0, right = 0;
        int leftNeeded[n], rightNeeded[n];
        fill(leftNeeded, leftNeeded + n, 0);
        fill(rightNeeded, rightNeeded + n, 0);
        
        for (int i = 0; i < n; ++i) {
            leftNeeded[i] = left, left += (machines[i] - sumPerMachine);
            rightNeeded[n - i - 1] = right, right += (machines[n - i - 1] - sumPerMachine);
        };
        for (int i = 0; i < n; ++i) {
            int movesAtCurr = (leftNeeded[i] + rightNeeded[i] > 0) ? max(leftNeeded[i], rightNeeded[i]) : -1 * (leftNeeded[i] + rightNeeded[i]);
            moves = max(moves, movesAtCurr);
        };        
        return sum % n == 0 ? moves : -1;
    };
};


/*
[4,0,0,4]
[4,0,4,0]
[4,4,0,0]
[9,1,8,8,9]
[0,0,0,0,0,14,0,0,0,0,0,0,0,0]
[1,0,5]
[0,3,0]
[0,2,0]

[ 9, 1, 8, 8, 9]
[ 2,-6, 1, 1, 2]
[ 0, 2,-4,-3,-2]
[-2, 4, 3, 2, 0]
[0,0,0,0,0,14,0,0,0,0,0,0,0,0]
[-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1]

*/