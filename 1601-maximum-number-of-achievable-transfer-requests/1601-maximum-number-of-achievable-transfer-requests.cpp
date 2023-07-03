class Solution {
public:
    int takeNotTakeRequest(int idx, int &n, int requestsTaken, vector<vector<int>>& requests, int *buildings) {
        if (idx == requests.size()) {
            for (auto i = 0; i < n; i++) {
                if (buildings[i] != 0) return 0;   
            };
            return requestsTaken;
        };
        
        int notTake = takeNotTakeRequest(idx + 1, n, requestsTaken, requests, buildings);
        buildings[requests[idx][0]]--, buildings[requests[idx][1]]++;
        int take = takeNotTakeRequest(idx + 1, n, requestsTaken + 1, requests, buildings);
        buildings[requests[idx][0]]++, buildings[requests[idx][1]]--;
        
        return max(take, notTake);
    };
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int buildings[n];
        for (auto i = 0; i < n; i++) buildings[i] = 0;
        return takeNotTakeRequest(0, n, 0, requests, buildings);
    };
};