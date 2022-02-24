class StockSpanner {
public:
    stack<pair<int, int>> s;
    
    int next(int price) {
        int curr = 1;
        while(!s.empty() && s.top().first <= price) curr += s.top().second, s.pop();
        s.push({price, curr});
        return curr;
    };
};
