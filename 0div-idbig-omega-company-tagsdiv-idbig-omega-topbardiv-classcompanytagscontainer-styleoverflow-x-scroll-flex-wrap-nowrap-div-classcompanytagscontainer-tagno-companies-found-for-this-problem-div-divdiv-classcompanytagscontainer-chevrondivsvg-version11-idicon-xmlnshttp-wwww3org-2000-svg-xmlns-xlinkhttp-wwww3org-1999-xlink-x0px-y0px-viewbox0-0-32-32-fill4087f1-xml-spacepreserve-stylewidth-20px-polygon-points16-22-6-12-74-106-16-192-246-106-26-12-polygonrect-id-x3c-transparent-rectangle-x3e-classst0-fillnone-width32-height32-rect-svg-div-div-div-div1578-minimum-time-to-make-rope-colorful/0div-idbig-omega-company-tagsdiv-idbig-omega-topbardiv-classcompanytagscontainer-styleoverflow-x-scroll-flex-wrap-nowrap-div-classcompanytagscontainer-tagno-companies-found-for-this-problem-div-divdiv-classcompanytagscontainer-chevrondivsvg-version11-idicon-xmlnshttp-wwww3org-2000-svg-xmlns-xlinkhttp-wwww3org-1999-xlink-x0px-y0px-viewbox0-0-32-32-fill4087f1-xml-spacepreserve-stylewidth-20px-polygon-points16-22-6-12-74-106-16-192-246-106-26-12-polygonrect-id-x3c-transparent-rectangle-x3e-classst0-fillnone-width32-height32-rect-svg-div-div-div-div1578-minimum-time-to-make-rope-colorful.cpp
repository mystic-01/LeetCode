class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = time.size(), i = 0, maxTime = 0, totalTime = 0;
        char curr = colors[0];
        while (i < n) {
            curr = colors[i], maxTime = time[i];
            while (i < n && colors[i] == curr) {
                totalTime += time[i], maxTime = max(maxTime, time[i]), ++i;
            };
            totalTime -= maxTime; 
        };
        return totalTime;
    };
};