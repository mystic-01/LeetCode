class DSU {
private:
    vector<int> parent, size;        
public:
    DSU (int &_size) {
        size.resize(_size, 0);
        parent.resize(_size);
        iota(begin(parent), end(parent), 0);
    };
    
    int findPar(int &i) {
        if (parent[i] == i) {
            return i;
        };
        return parent[i] = findPar(parent[i]);
    };
    void unionBySize(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        
        if (parU != parV) {
            if (size[parU] > size[parV]) {
                parent[parV] = parU;
                size[parU] += size[parV];
            } else {
                parent[parU] = parV;
                size[parU] += size[parV];
            };
        };
    };    
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int idx = 0;
        unordered_map<string, int> m, m2;
        unordered_map<int, string> reverseM, reverseM2;
        for (auto &v : accounts) {
            if (m.find(v[0]) == m.end()) {
                reverseM[idx] = v[0];
                m[v[0]] = idx++;
            };
        };
        idx = 0;
        unordered_map<int, int> par;
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                if (m2.find(vec[i]) == m.end()) {
                    par[idx] = m[vec[0]];
                    reverseM2[idx] = vec[i];
                    m2[vec[i]] = idx++;
                };
            };            
        };  
        
        DSU *dsu = new DSU(idx);        
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size() - 1; ++i) {
                dsu->unionBySize(m2[vec[i]], m2[vec[i + 1]]);
            };            
        };          
      
        unordered_map<string, set<string>> stringLeader;
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                int currPar = dsu->findPar(m2[vec[i]]);
                stringLeader[reverseM2[currPar]].insert(vec[i]);
            };            
        };         
        
        vector<vector<string>> ans;
        for (auto &it : stringLeader) {
            ans.push_back({});
            ans.back().push_back(reverseM[par[m2[it.first]]]);
            for (auto &str : it.second) {
                ans.back().push_back(str);            
            };
        };
        return ans;
    };
};







