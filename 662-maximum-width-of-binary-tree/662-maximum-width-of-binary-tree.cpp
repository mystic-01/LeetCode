class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if (!root) return 0;
        q.push({root, 0});
        
        long long width = 1; 
        while (!q.empty()) {
            int size = q.size();
            long long minVertical = q.front().second, maxVertical = q.back().second;
            
            for (auto i = 0; i < size; i++) {
                TreeNode *front = q.front().first;
                long long idx = q.front().second - minVertical;    
                
                if (front->left) q.push({front->left, 2 * idx + 1}); 
                if (front->right) q.push({front->right, 2 * idx + 2}); 
                q.pop();
            };
            width = max(width, maxVertical - minVertical + 1);
        };
        return (int)width;
    };
};

// [1,3,2,5,null,null,9,6,null,null,7]
// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
