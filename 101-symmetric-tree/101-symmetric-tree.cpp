// DFS
class Solution {
public:
    int isEqual (TreeNode* one, TreeNode* two) {
        return !one || !two ? one == two : one->val == two->val && isEqual(one->left, two->right) && 
            isEqual(one->right, two->left);
    };
    
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
    };
};

// BFS
// class Solution {
// public:
    
//     bool isSymmetric(TreeNode* root) {
//         deque<TreeNode*> dq;
//         dq.push_front(root->left);
//         dq.push_back(root->right);
        
//         while (!dq.empty()) {
//             int size = dq.size();
//             for (auto i = 0, j = size - 1; i < j; i++, j--) {
//                 TreeNode* one = dq.front(), * two = dq.back(); 
//                 dq.pop_back(), dq.pop_front();
//                 if (!one && !two) continue;
//                 else if (!one || !two) return false;
//                 else if (one->val != two->val) return false;
//                 dq.push_front(one->right);
//                 dq.push_front(one->left);
//                 dq.push_back(two->left);
//                 dq.push_back(two->right);
//             };
//         };
//         return true;
//     };
// };


