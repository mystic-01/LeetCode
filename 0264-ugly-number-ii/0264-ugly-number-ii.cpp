class Solution {
public:
    int nthUglyNumber(int n) {
        long long nthUglyNumber = 1;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1LL);
        set<long long> uglyNumbers;
        
        while (!pq.empty() && n) {
            long long top = pq.top();
            pq.pop();
            if (!uglyNumbers.count(top)) {        
                nthUglyNumber = top, --n; 
                uglyNumbers.insert(top);                
                if (top <= LLONG_MAX - top) {
                    pq.push(top * 2LL);
                    if (top + top <= LLONG_MAX - top) {
                        pq.push(top * 3LL);
                        if (top + top + top <= LLONG_MAX - top - top) {
                            pq.push(top * 5LL);                            
                        };
                    };
                };
            };
        };
        return nthUglyNumber;
    };
};