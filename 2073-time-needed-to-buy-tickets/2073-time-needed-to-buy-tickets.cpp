class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), time = 0;
        for (int i = 0; i < n; i++) {
            time += min(tickets[k] - ((i <= k) ? 0 : 1), tickets[i]);
        };
        return time;
    };
};
