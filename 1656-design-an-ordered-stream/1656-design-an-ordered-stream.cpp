class OrderedStream {
public:
    int idx = 0;
    vector<string> stream;
    OrderedStream(int n) {
        stream.resize(n);
    };
    
    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        vector<string> ans;
        for (; idx < stream.size() && stream[idx].size(); ++idx) {
            ans.push_back(stream[idx]);                            
        };
        return ans;
    };
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */