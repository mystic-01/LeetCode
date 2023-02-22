class Solution {
public:
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), multiplier = ceil((double)n / days);
        int lo = (*max_element(weights.begin(), weights.end())),  hi = lo * multiplier;
        int least = hi; 
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, capacity = mid, daysTaken = 1;            
            for (auto i = 0; i < n; i++) {
                if (capacity - weights[i] < 0) daysTaken++, capacity = mid;
                capacity -= weights[i];
            };
            if (daysTaken > days) lo = mid + 1; 
            else hi = mid, least = min(least, mid);
        };
        
        return least;
    };
};