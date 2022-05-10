class RandomizedSet {
public:
    vector<int> v;
    map<int, int> mp;
    
    RandomizedSet() {   
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = v[v.size() - 1];
        swap(v[mp[val]], v[v.size() - 1]);
        mp[last] = mp[val];
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        // srand(time(nullptr));
        // int idx = ; 
        // cout << rand() << " ";
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */