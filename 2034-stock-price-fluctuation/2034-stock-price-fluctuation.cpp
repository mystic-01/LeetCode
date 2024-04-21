class StockPrice {
private:
    int currentIdx = -1;    
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> maxPq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;
    
public:
    StockPrice() {
                
    };
    
    void update(int timestamp, int price) {
        if (m.find(timestamp) != m.end()) {
            while (minPq.size() && minPq.top().second == timestamp) {
                minPq.pop();    
            };    
            while (maxPq.size() && maxPq.top().second == timestamp) {
                maxPq.pop();    
            };                
        };
        maxPq.push({price, timestamp});
        minPq.push({price, timestamp});
        
        if (timestamp > currentIdx) {
            currentIdx = timestamp;     
        };
        m[timestamp] = price;
    };
    
    int current() {
        return m[currentIdx];        
    };
    
    int maximum() {
        while (maxPq.size() && maxPq.top().first != m[maxPq.top().second]) {
            // stale data
            maxPq.pop();
        };
        return maxPq.top().first;
    };
    
    int minimum() {
        while (minPq.size() && minPq.top().first != m[minPq.top().second]) {
            // stale data
            minPq.pop();
        };
        return minPq.top().first;
    };
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */