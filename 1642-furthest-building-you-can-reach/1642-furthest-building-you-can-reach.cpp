class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size(), i = 0;
        while (i + 1 < n) {
            if (heights[i] < heights[i + 1]) {
                int diff = heights[i + 1] - heights[i];                
                pq.push(diff);                        
                if (pq.size() > ladders) {
                    if (bricks >= pq.top()) {
                        bricks -= pq.top();
                        pq.pop();
                    } else {
                        break;
                    };
                };
            };
            ++i;
        };
        return i;               
    };
};