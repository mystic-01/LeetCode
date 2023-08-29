class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), minPenalty = 0, minIdx = 0;         
        
        // If we closed shop at idx = 0
        for (int i = 0; i < n; i++) minPenalty += (customers[i] == 'Y');                        
        
        int penalty = minPenalty;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;
            if (penalty < minPenalty) minIdx = i + 1, minPenalty = penalty;
            // cout << penalty << " ";
        };
        
        // cout << "\n";
        
        return minIdx;
    };
};