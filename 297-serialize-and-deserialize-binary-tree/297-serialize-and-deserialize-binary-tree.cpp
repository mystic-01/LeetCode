class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if (!root) return data;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr) {
                    q.push(curr->left), q.push(curr->right);
                    data += to_string(curr->val) + ",";            
                } else {
                    data += "#,";
                };
            };
        };
        return data;
    };

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.length()) return nullptr;
        stringstream ss(data);
        string temp = "";
        getline(ss, temp, ',');
        TreeNode* root = new TreeNode(stoi(temp));
        
        queue<TreeNode*> q;
        q.push(root);
    
        while (!q.empty()) {
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                getline(ss, temp, ',');
                if (temp == "#") curr->left = nullptr;
                else {
                    curr->left = new TreeNode(stoi(temp));
                    q.push(curr->left);
                };
                
                getline(ss, temp, ',');
                if (temp == "#") curr->right = nullptr;
                else {
                    curr->right = new TreeNode(stoi(temp));
                    q.push(curr->right);
                };
            };
        };
        return root;
    };
};






