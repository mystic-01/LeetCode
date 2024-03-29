class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        int n = events.size(), i = 0, day = 0, totEvents = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (i < n || pq.size()) {
            if (pq.empty()) {
                day = events[i][0];      
            };
            while (i < n && events[i][0] <= day) {
                pq.push(events[i++][1]);        
            };
            if (pq.size()) {
                ++totEvents, ++day;
                pq.pop();
            };
            while (pq.size() && pq.top() < day) {
                pq.pop();    
            };
        };
        return totEvents;
    };
};
