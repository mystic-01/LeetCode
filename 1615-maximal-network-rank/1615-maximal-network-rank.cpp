class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> adjList(n);
        
        int maxRank = INT_MIN;
        
        for (auto &vec : roads) {
            adjList[vec[0]].insert(vec[1]);
            adjList[vec[1]].insert(vec[0]);
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    int rank = adjList[i].size() + adjList[j].size() + (adjList[i].find(j) == adjList[i].end() ? 0 : -1); 
                    maxRank = max(maxRank, rank);    
                };
            };        
        };
        
        return maxRank;
    };
};

/*

0->1->2->3
      |
      4

7<-5->6

*/