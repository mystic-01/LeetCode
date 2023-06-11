class SnapshotArray {

private:
    int snapId = 0;
    vector<vector<int>> mp;

public:
    SnapshotArray(int len) {
        mp.resize(len);
        for (auto i = 0; i < len; i++) {
            mp[i].push_back(0);
        };
    };
    
    void set(int idx, int val) {
        if (snapId < mp[idx].size()) mp[idx][snapId] = val;
        else {
            int size = mp[idx].size();
            while (size++ < snapId) {
                mp[idx].push_back(mp[idx].back());            
            };
            mp[idx].push_back(val);
        };
    };
    
    int snap() {
        return snapId++;
    };
    
    int get(int idx, int snap_id) {
        if (snap_id < mp[idx].size()) return mp[idx][snap_id];
        else return mp[idx].back();
    };
};

/*
0 : [[0], [6], [0]]
1 : [[0], [6], [0]]
2 : [[0], [6, 19], [0]]

*/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */