class BIT {
public:
    int size = 0;
    vector<int> bitTree;
    
    BIT(int _size) {
        size = _size + 2;
        bitTree.resize(size, 0);
    };        
    
    int query(int idx) {
        int sum = 0;
        for (int i = idx; i > 0; i -= (i & (-i))) {
            sum += bitTree[i];
        };          
        return sum;
    };    

    void update(int idx, int val) {
        for (int i = idx; i < size; i += (i & (-i))) {
            bitTree[i] += val;     
        };            
    };
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int q = queries.size();
        vector<int> ans(q), hash(m + 1);
        BIT *bit = new BIT(q + m + 1); 
        for (int i = 1; i <= m; ++i) {
            hash[i] = q + i;
            bit->update(q + i, 1);
        };
        int frontIdx = q;
        for (int i = 0; i < q; ++i) {
            int originalPosition = hash[queries[i]] - 1;
            int sum = bit->query(originalPosition);
            ans[i] = sum;
            bit->update(frontIdx, 1);                    
            bit->update(hash[queries[i]], -1);                    
            hash[queries[i]] = frontIdx--;                        
        };
        return ans;
    };
};