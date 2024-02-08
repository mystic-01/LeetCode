class Solution {
public:
    int nthUglyNumber(int n) {
        int nthUglyNumber = 1, maxInt = 2147483647;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> visited;
        pq.push(1);
        visited.insert(1);   
        
        // auto visitAndInsertInPq = [&pq, &visited](int &val) {
            // pq.push(val);
            // visited.insert(val);               
        // };
        
        while (!pq.empty() && --n) {
            int num = pq.top();
            pq.pop();
            
            if (num <= maxInt - num) {
                int numX2 = num + num;
                if (!visited.count(numX2)) {   
                    pq.push(numX2);
                    visited.insert(numX2); 
                };
                if (numX2 <= maxInt - num) {
                    int numX3 = numX2 + num; 
                    if (!visited.count(numX3)) {    
                        pq.push(numX3);
                        visited.insert(numX3); 
                    };
                    if (numX3 <= maxInt - numX2) {
                        int numX5 = numX3 + numX2;
                        if (!visited.count(numX5)) {    
                            pq.push(numX5);
                            visited.insert(numX5); 
                        };
                    };
                };
            };
        };
        return pq.top();
    };
};