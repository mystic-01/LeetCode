class Solution {
public:
    int minOperationsMaxProfit(vector<int>& nums, int boardingCost, int runningCost) {
        int n = nums.size(), waiting = 0, onboard = 0;
        int rotations = 0, profit = 0, maxRotations = -1, maxProfit = 0;        
        int lastSlot = 0;
        
        for (int i = 0; i < n; ++i) {
            int addOnboard = 0, waitingOnboarded = 0;
            addOnboard = min(4, nums[i]);                
            if (addOnboard < 4 && waiting) {
                waitingOnboarded = min(4 - (addOnboard), waiting);                    
            };
            addOnboard += waitingOnboarded;
            // cout << waitingOnboarded << "\n";
            waiting += nums[i] - addOnboard;
            onboard += addOnboard;            
            ++rotations;                
            profit = (onboard * boardingCost) - (rotations * runningCost);
            // cout << addOnboard << " " << waiting << " " << profit << " " << onboard << " " << rotations << " - " << lastSlot << "\n";
            // cout << addOnboard << " " << waiting << " " << profit << " " << maxProfit << " " << onboard << " " << rotations << " - " << lastSlot << "\n";
            if (profit > maxProfit) {
                maxProfit = profit, maxRotations = rotations;
            };
        };
        while (waiting > 0) {
            int addOnboard = min(waiting, 4);
            waiting -= addOnboard;
            onboard += addOnboard;            
            ++rotations;                
            profit = (onboard * boardingCost) - (rotations * runningCost);
            // cout << addOnboard << " " << waiting << " " << profit << " " << onboard << " " << rotations << " - " << lastSlot << "\n";
            if (profit > maxProfit) {
                maxProfit = profit, maxRotations = rotations;
            };         
        };
        // cout << "\n";
        return maxRotations; 
    };
};