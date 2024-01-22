class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size(), sum = accumulate(begin(machines), end(machines), 0); 
        int sumPerMachine = sum / n, moves = 0, leftGive[n], rightGive[n], left = 0, right = 0;

        fill(leftGive, leftGive + n, 0);
        fill(rightGive, rightGive + n, 0);
        
        for (int i = 0; i < n; ++i) {
            leftGive[i] = left, left += (machines[i] - sumPerMachine);
            rightGive[n - i - 1] = right, right += (machines[n - i - 1] - sumPerMachine);
        };
        for (int i = 0; i < n; ++i) {
            int movesAtCurr = (leftGive[i] + rightGive[i] > 0) ? max(leftGive[i], rightGive[i]) : -1 * (leftGive[i] + rightGive[i]);
            moves = max(moves, movesAtCurr);
        };        
        return sum % n == 0 ? moves : -1;
    };
};