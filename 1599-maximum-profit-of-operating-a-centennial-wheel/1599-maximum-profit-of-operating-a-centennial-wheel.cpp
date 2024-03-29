class Solution {
public:
    int minOperationsMaxProfit(vector<int>& nums, int boardingCost, int runningCost) {
        int n = nums.size(), waiting = 0, onboard = 0, cost = 0;
        int rotations = 0, profit = 0, maxRotations = -1, maxProfit = 0;        
        
        for (int i = 0; i < n; ++i) {
            int addOnboard = min(4, nums[i]), waitingOnboarded = 0;                
            if (addOnboard < 4 && waiting) {
                waitingOnboarded = min(4 - addOnboard, waiting);                    
            };
            addOnboard += waitingOnboarded;
            waiting += nums[i] - addOnboard;
            onboard += addOnboard;            
            ++rotations, cost += runningCost;                
            profit = (onboard * boardingCost) - cost;
            if (profit > maxProfit) {
                maxProfit = profit, maxRotations = rotations;
            };
        };
        while (waiting > 0) {
            int addOnboard = min(waiting, 4);
            waiting -= addOnboard;
            onboard += addOnboard;            
            ++rotations, cost += runningCost;                
            profit = (onboard * boardingCost) - cost;
            if (profit > maxProfit) {
                maxProfit = profit, maxRotations = rotations;
            };         
        };
        return maxRotations; 
    };
};