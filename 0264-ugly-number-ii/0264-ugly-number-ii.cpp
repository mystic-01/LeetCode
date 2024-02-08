class Solution {
public:
    int nthUglyNumber(int n) {
        int nthUglyNumber = 1, maxInt = 2147483647;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        set<int> visited;
        
        while (!pq.empty() && n) {
            int top = pq.top();
            pq.pop();
            if (!visited.count(top)) {        
                nthUglyNumber = top, --n; 
                visited.insert(top);                
                if (top <= maxInt - top) {
                    pq.push(top * 2);
                    if (top + top <= maxInt - top) {
                        pq.push(top * 3);
                        if (top + top + top <= maxInt - top - top) {
                            pq.push(top * 5);                            
                        };
                    };
                };
            };
        };
        return nthUglyNumber;
    };
};