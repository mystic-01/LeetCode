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
    void unionBySize(int &u, int &v) {
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
        unordered_map<string, int> nameToIdx, emailToIdx;
        unordered_map<int, string> idxToEmail;
        for (auto &v : accounts) {
            if (nameToIdx.find(v[0]) == nameToIdx.end()) {
                nameToIdx[v[0]] = idx++;
            };
        };
        idx = 0;
        unordered_map<int, string> par;
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                if (emailToIdx.find(vec[i]) == emailToIdx.end()) {
                    par[idx] = vec[0];
                    idxToEmail[idx] = vec[i];
                    emailToIdx[vec[i]] = idx++;
                };
            };            
        };  
        
        DSU *dsu = new DSU(idx);        
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size() - 1; ++i) {
                dsu->unionBySize(emailToIdx[vec[i]], emailToIdx[vec[i + 1]]);
            };            
        };          
      
        unordered_map<string, set<string>> emailSets;
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                int currPar = dsu->findPar(emailToIdx[vec[i]]);
                emailSets[idxToEmail[currPar]].insert(vec[i]);
            };
        };         
        
        vector<vector<string>> ans;
        for (auto &it : emailSets) {
            ans.push_back({});
            int currStrLeaderIdx = emailToIdx[it.first];
            ans.back().push_back(par[currStrLeaderIdx]);
            for (auto &str : it.second) {
                ans.back().push_back(str);            
            };
        };
        return ans;
    };
};







