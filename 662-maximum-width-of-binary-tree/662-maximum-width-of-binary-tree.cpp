class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if (!root) return 0;
        q.push({root, 0});
        
        int width = 1; 
        while (!q.empty()) {
            int size = q.size();
            int minVertical = q.front().second, maxVertical = q.back().second;
            
            for (auto i = 0; i < size; i++) {
                TreeNode *front = q.front().first;
                int idx = q.front().second - minVertical;    
                
                if (front->left) q.push({front->left, (long long)2 * idx + 1}); 
                if (front->right) q.push({front->right, (long long)2 * idx + 2}); 
                q.pop();
            };
            width = max(width, maxVertical - minVertical + 1);
        };
        return width;
    };
};

// [1,3,2,5,null,null,9,6,null,null,7]
// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
