class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> uglyNumbers(1691, 0);
        
        int ans = 1, idx = 1, nOriginal = n;
        if (uglyNumbers[n] != 0) {
            return uglyNumbers[n];
        };
        
        n = 1690;
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> visited;
        pq.push(1);
        
        while (!pq.empty() && n) {
            int num = pq.top();
            pq.pop();
            if (!visited.count(num)) {        
                visited.insert(num);
                uglyNumbers[idx++] = ans = num, --n;
                
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
        return uglyNumbers[nOriginal];
    };
};