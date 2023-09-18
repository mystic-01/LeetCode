class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), time = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k) time += min(tickets[k], tickets[i]);
            else time += min(tickets[k] - 1, tickets[i]);            
        };
        return time;
    };
};
