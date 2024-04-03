static const int offsets[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Node {
public:
    Node *links[26] = {nullptr};
    bool isEnd = false;
    Node() {
        
    };
    bool contains(char &ch) {
        return links[ch - 'a'] != nullptr;       
    };
    void put(char &ch) {
        links[ch - 'a'] = new Node();
    };
};

class Trie {
public:
    Node *root = new Node();

    bool search(string &str) {
        Node *node = root;
        for (char &ch : str) {
            if (!node->contains(ch)) {
                return false;
            };
            node = node->links[ch - 'a'];
        };
        return true;
    };    
    void insert(string &str) {
        Node *node = root;
        for (char &ch : str) {
            if (!node->contains(ch)) {
                node->put(ch);
            };
            node = node->links[ch - 'a'];
        };
        node->isEnd = true;
    };    
};

class Solution {
public:
    void recurse(int a, int b, string &curr, vector<vector<char>>& board, Node *node, unordered_set<string> &ansSet) {
        if (node->isEnd) {
            ansSet.insert(curr);                    
        };        
        for (int k = 0; k < 4; ++k) {
            int i = a + offsets[k][0], j = b + offsets[k][1];
            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] != ' ') {
                if (node->contains(board[i][j])) {
                    char ch = board[i][j];
                    Node *temp = node->links[ch - 'a'];
                    board[i][j] = ' ';
                    curr += ch;
                    recurse(i, j, curr, board, temp, ansSet);
                    curr.pop_back();
                    board[i][j] = ch;
                };
            };
        };        
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        string curr = "";                
        unordered_set<string> ansSet;
        for (auto &str : words) {
            trie->insert(str);
        };
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                Node *node = trie->root;
                if (node->contains(board[i][j])) {
                    char ch = board[i][j];
                    board[i][j] = ' ';
                    curr += ch;
                    Node *temp = node->links[ch - 'a'];
                    recurse(i, j, curr, board, temp, ansSet);                
                    curr.pop_back();
                    board[i][j] = ch;
                };
            };
        };
        vector<string> ans(begin(ansSet), end(ansSet));
        return ans;
    };
};