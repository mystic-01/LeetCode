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
        unordered_map<string, int> getIdxFromEmail;
        unordered_map<int, string> getEmailFromIdx;
        unordered_map<int, string> getNameFromIdx;
        
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                if (getIdxFromEmail.find(vec[i]) == getIdxFromEmail.end()) {
                    getEmailFromIdx[idx] = vec[i];
                    getIdxFromEmail[vec[i]] = idx++;
                };
            };            
        };  
        
        DSU *dsu = new DSU(idx);        
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size() - 1; ++i) {
                dsu->unionBySize(getIdxFromEmail[vec[i]], getIdxFromEmail[vec[i + 1]]);
            };            
        };          
      
        unordered_map<string, set<string>> emailSets;
        for (auto &vec : accounts) {
            for (int i = 1; i < vec.size(); ++i) {
                int currParEmailIdx = dsu->findPar(getIdxFromEmail[vec[i]]);
                emailSets[getEmailFromIdx[currParEmailIdx]].insert(vec[i]);
                getNameFromIdx[currParEmailIdx] = vec[0];
            };
        };         
        
        idx = 0;
        vector<vector<string>> ans(emailSets.size());
        for (auto &it : emailSets) {
            int currEmailLeaderIdx = getIdxFromEmail[it.first];
            ans[idx].push_back(getNameFromIdx[currEmailLeaderIdx]);
            for (auto &str : it.second) {
                ans[idx].push_back(str);            
            };
            ++idx;
        };
        return ans;
    };
};







