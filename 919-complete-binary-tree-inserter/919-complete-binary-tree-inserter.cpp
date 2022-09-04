/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    TreeNode* northStar, * nextParent = nullptr;
    
public:
    CBTInserter(TreeNode* root) {
        northStar = root;
    };
    
    int insert(int val) {
        if (nextParent) {
            nextParent->right = new TreeNode(val);
            int ans = nextParent->val;
            nextParent = nullptr;
            return ans;
        };
        queue<TreeNode*> q;
        q.push(northStar);
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                else {
                    curr->left = new TreeNode(val);
                    nextParent = curr;
                    return curr->val;
                };
                if (curr->right) q.push(curr->right);
                else {
                    curr->right = new TreeNode(val);
                    return curr->val;
                };
            };
        };
        return 0;
    };
    
    TreeNode* get_root() {
        return northStar;        
    };
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */