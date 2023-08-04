class Solution {
public:
    int dfs(int node, vector<vector<int>> &adjList, vector<int> &ans, vector<int> &quiet) {
        if (ans[node] != -1) return ans[node];
        
        int curr = node;
        for (auto &child : adjList[node]) {
            int childAns = dfs(child, adjList, ans, quiet);
            if (quiet[childAns] < quiet[curr]) curr = childAns;            
        };
        return ans[node] = curr;
    };

    
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);
        vector<vector<int>> adjList(n);
        
        for (auto &vec : richer) adjList[vec[1]].push_back(vec[0]);
        
        for (int i = 0; i < n; i++) if (ans[i] == -1) dfs(i, adjList, ans, quiet);
                
        return ans;
    };
};

/*

1 : 0
2 : 1
3 : 1, 7
4 : 3
5 : 3
6 : 3

0 : 1
1 : 2, 3
7 : 3
3 : 4, 5, 6



*/