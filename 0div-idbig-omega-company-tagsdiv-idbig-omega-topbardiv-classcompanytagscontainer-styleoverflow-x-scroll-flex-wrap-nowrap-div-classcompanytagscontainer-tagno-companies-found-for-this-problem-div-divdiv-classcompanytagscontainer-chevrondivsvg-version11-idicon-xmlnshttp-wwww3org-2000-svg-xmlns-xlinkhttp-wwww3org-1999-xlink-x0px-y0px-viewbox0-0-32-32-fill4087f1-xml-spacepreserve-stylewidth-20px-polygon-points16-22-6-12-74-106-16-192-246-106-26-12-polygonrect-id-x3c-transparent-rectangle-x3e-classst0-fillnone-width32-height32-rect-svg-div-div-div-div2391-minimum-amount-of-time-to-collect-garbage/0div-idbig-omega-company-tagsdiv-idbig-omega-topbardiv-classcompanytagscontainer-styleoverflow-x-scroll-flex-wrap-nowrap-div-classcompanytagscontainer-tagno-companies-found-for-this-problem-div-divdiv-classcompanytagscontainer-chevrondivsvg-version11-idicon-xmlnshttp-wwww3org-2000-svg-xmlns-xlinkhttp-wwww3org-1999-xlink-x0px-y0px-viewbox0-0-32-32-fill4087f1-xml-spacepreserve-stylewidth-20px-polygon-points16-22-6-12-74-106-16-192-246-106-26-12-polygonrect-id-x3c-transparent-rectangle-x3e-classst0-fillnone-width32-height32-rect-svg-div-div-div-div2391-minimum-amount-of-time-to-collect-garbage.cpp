class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int totalTime = 0, travelTime = 0, i = -1, gTime = 0, pTime = 0, mTime = 0;
        for (string &str : garbage) {
            totalTime += str.size();            
            if (i++ >= 0) travelTime += travel[i - 1];
            
            for (auto &ch : str) {
                if (ch == 'G') gTime = travelTime;
                else if (ch == 'P') pTime = travelTime;
                else if (ch == 'M') mTime = travelTime;
            };
        };
        return totalTime + gTime + pTime + mTime;
    };
};