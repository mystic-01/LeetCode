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
        int ans = 0;
        Trie() {
            root = new Node();        
        };
        
        void insert(int num) {
            Node* temp = root;
            for (auto i = 31; i>= 0; i--) {
                int bit = (num >> i) & 1;
                if (!temp->containsKey(bit)) temp->put(bit);
                temp = temp->links[bit];
            };
        };
    
        void getMaxXOR(int x) {
            Node* temp = root;  
            int maxXOR = 0;
            for (auto i = 31; i>= 0; i--) {
                int bit = (x >> i) & 1;
                if (temp->containsKey(1 - bit))
                    maxXOR = (1 << i) | maxXOR, temp = temp->links[1 - bit];
                else 
                    temp = temp->links[bit];
            };
            ans = max(ans, maxXOR);
        };
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie root = Trie();
        for (auto i = 0; i < nums.size(); i++) root.insert(nums[i]);
        for (auto i = 0; i < nums.size(); i++) root.getMaxXOR(nums[i]);
        return root.ans;        
    };
};
