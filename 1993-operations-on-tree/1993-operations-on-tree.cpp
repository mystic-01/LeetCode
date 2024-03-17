class LockingTree {
private:
    int n = 0;
    vector<int> parent;
    vector<int> isLocked;
public:
    LockingTree(vector<int> &_parent) {
        parent = _parent;
        n = parent.size();
        isLocked.resize(n, 0);
    };
    
    bool lock(int num, int user) {
        if (isLocked[num]) {
            return false;
        };
        isLocked[num] = user;
        return true;
    };
    
    bool unlock(int num, int user) {
        if (isLocked[num] == user) {
            isLocked[num] = 0;
            return true;        
        };
        return false;
    };
    
    int getParent(int i, int &num, vector<int> &masterParent) {
        if (masterParent[i] == -1 || masterParent[i] == num) {
            return masterParent[i];     
        };            
        return masterParent[i] = getParent(masterParent[i], num, masterParent);
    };
    
    bool upgrade(int num, int user) {
        int val = num;
        while (val != -1) {
            if (isLocked[val]) {
                return false;
            };
            val = parent[val];
        };
        bool unlockedAnyNode = false;
        vector<int> masterParent = parent;
        for (int i = 0; i < n; ++i) {
            int val = getParent(i, num, masterParent); 
            if (val == num && isLocked[i]) {
                unlockedAnyNode = true;
                isLocked[i] = 0;                    
            };
        };
        if (unlockedAnyNode) {
            isLocked[num] = user;
        };
        return unlockedAnyNode;
    };
};