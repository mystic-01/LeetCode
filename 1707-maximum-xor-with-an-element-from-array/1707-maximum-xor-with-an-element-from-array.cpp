
struct Node {
    Node* links[2];
    
    bool containsKey(int bit) {
        return links[bit];                        
    };
    
    void put(int bit) {
        links[bit] = new Node();        
    };
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();            
        };
    
        void insert(int num) {
            Node* temp = root;
            for (auto i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!temp->containsKey(bit)) temp->put(bit);
                temp = temp->links[bit];
            };
        };
     
        int getMaxXOR(int x) {
            Node* temp = root;
            int maxXOR = 0;
            for (auto i = 31; i >= 0; i--) {
                int bit = (x >> i) & 1;
                if (temp->containsKey(1 - bit)) {
                    maxXOR = (1 << i) | maxXOR;
                    temp = temp->links[1 - bit];
                } else if (temp->containsKey(bit)) {
                    temp = temp->links[bit];
                } else {
                    return -1;
                };
            };
            return maxXOR;
        };
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        int q = queries.size(), j = 0;
        vector<int> ans(q);
        for (auto i = 0; i < q; i++) {
            swap(queries[i][0], queries[i][1]);
            queries[i].push_back(i);        
        };
        
        sort(arr.begin(), arr.end());
        sort(queries.begin(), queries.end());
        
        Trie rootus = Trie();
    
        for (auto i = 0; i < q; i++) {
            int limit = queries[i][0], x = queries[i][1], idx = queries[i][2];
            while (j < arr.size() && arr[j] <= limit) rootus.insert(arr[j]), j++;   
            ans[idx] = rootus.getMaxXOR(x);
        };
        return ans;
    };
};






