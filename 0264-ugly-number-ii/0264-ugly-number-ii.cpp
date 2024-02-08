class Solution {
public:
    int nthUglyNumber(int n) {
        int ans = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> visited;
        pq.push(1);
        
        while (!pq.empty() && n) {
            int num = pq.top();
            pq.pop();
            if (!visited.count(num)) {        
                visited.insert(num);
                ans = num, --n;
                if (num <= INT_MAX - num) {
                    pq.push(num * 2);
                    if (num + num <= INT_MAX - num) {
                        pq.push(num * 3);
                        if (num + num + num <= INT_MAX - num - num) {
                            pq.push(num * 5);
                        };
                    };
                };
            };    
        };
        return ans;
    };
};