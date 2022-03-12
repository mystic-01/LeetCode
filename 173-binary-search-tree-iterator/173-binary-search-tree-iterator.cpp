class BSTIterator {
private:
    stack<TreeNode*> s;
    
    void pushAll(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        };
    };

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    };
    
    int next() {
        if (s.empty()) return -1;
        TreeNode* curr = s.top();
        s.pop();
        pushAll(curr->right);
        return curr->val;
    };
    
    bool hasNext() {
        return !s.empty();    
    };
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */