class Solution {
public:
    void updateMaxRank(vector<int> &pair, int *degree, int &maxRank, vector<vector<int>>& roads) {
        auto findAB = find(roads.begin(), roads.end(), pair);
        bool pairFound = findAB != roads.end();

        if (!pairFound) {
            swap(pair[0], pair[1]);
            auto findBA = find(roads.begin(), roads.end(), pair);
            pairFound = findBA != roads.end();
        };
                    
        int rank = degree[pair[0]] + degree[pair[1]] + (pairFound ? -1 : 0);
        maxRank = max(maxRank, rank);
    };
    
    void updateList(int &idx, int &curr, int &best, int &secondBest, vector<int> &bestList, vector<int> &secondBestList) {
        if (curr >= best) {
            if (curr > best) {
                secondBest = best, secondBestList = bestList;
                best = curr, bestList = vector<int>(); 
            };
            bestList.push_back(idx);  
        } else if (curr >= secondBest) {
            if (curr > secondBest) {
                secondBest = curr, secondBestList = vector<int>(); 
            };
            secondBestList.push_back(idx);              
        };
    };
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = INT_MIN, degree[n], best = INT_MIN, secondBest = INT_MIN;
        vector<int> bestList, secondBestList;
        
        for (int i = 0; i < n; i++) degree[i] = 0;
        for (auto &vec : roads) ++degree[vec[0]], ++degree[vec[1]];
        for (int i = 0; i < n; i++) updateList(i, degree[i], best, secondBest, bestList, secondBestList);
            

        if (bestList.size() > 1) {
            for (int i = 0; i < bestList.size(); i++) {
                for (int j = i + 1; j < bestList.size(); j++) {
                    vector<int> pair = {bestList[i], bestList[j]};
                    updateMaxRank(pair, degree, maxRank, roads);
                };            
            };
        } else {
            for (int j = 0; j < secondBestList.size(); j++) {
                vector<int> pair = {bestList[0], secondBestList[j]};
                updateMaxRank(pair, degree, maxRank, roads);
            };     
        };
        
        return maxRank;
    };
};



