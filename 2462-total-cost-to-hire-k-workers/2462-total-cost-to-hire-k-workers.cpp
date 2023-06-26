class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        
        int i = 0, j = costs.size() - 1;
        
        while (i < candidates) pq1.push(costs[i++]);
        while (j >= i && candidates-- > 0) pq2.push(costs[j--]);

        while (k--) {
            if (pq1.size() && (!pq2.size() || pq1.top() <= pq2.top())) {
                ans += pq1.top();
                pq1.pop();
                if (i <= j) pq1.push(costs[i++]);
            } else {
                ans += pq2.top();
                pq2.pop();
                if (j >= i) pq2.push(costs[j--]);
            };
        };
        
        return ans;
    };
};