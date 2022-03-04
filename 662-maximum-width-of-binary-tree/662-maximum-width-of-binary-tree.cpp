class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if (!root) return 0;
        q.push({root, 0});
        
        int width = 1; 
        while (!q.empty()) {
            int size = q.size();
            int left = q.front().second, right = q.back().second;
            width = max(width, right - left + 1);
            
            for (auto i = 0; i < size; i++) {
                TreeNode *front = q.front().first;
                int idx = q.front().second - left;    
                
                if (front->left) q.push({front->left, (long long)2 * idx + 1}); 
                if (front->right) q.push({front->right, (long long)2 * idx + 2}); 
                q.pop();
            };
        };
        return width;
    };
};