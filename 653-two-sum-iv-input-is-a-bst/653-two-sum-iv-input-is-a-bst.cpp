class BSTIterator {
private:
    stack<TreeNode*> st;
    bool isReverse;

    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = isReverse ? root->right : root->left;
        };    
    };
    
public:
    BSTIterator(TreeNode* root, bool isReverseIt) {
        isReverse = isReverseIt;
        pushAll(root);    
    };    
    
    int next() {
        if (st.empty()) return -1e9;
        TreeNode* curr = st.top();
        st.pop();
        pushAll(isReverse ? curr->left : curr->right);
        return curr->val;
    };
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator first = BSTIterator(root, false);
        BSTIterator last = BSTIterator(root, true);
        
        int lo = first.next(), hi = last.next();
        while (lo < hi) {
            if (lo + hi == k) return true;
            else if (lo + hi < k) lo = first.next();
            else hi = last.next();
        };
        return false;
    };
};