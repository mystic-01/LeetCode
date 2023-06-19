class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size() - 1, totalTime = 0, gIdx = -1, mIdx = -1, pIdx = -1;
        
        for (auto i = 1; i < travel.size(); i++) travel[i] += travel[i - 1];
    
        for (auto i = n; i >= 0; i--) {
            if (gIdx == -1 || mIdx == -1 || pIdx == -1) {
                for (auto &ch : garbage[i]) {
                    if (gIdx == -1 && ch == 'G') gIdx = i;
                    else if (mIdx == -1 && ch == 'M') mIdx = i;
                    else if (pIdx == -1 && ch == 'P') pIdx = i;
                };
            };       
            totalTime += garbage[i].size();
        };
        
        if (gIdx > 0) totalTime += (travel[gIdx - 1]); 
        if (mIdx > 0) totalTime += (travel[mIdx - 1]); 
        if (pIdx > 0) totalTime += (travel[pIdx - 1]); 
        
        return totalTime;
    };
};