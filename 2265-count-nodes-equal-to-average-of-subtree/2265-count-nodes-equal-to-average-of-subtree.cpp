struct nodesAndSum {
    int nodes;
    int sum;
    
    nodesAndSum(int _nodes, int _sum) {
        nodes = _nodes, sum = _sum;        
    };
};

class Solution {
public:
    nodesAndSum countNodes(TreeNode* root, int &goodNodes) {
        if (!root) return nodesAndSum(0, 0);
        
        nodesAndSum left = countNodes(root->left, goodNodes);
        nodesAndSum right = countNodes(root->right, goodNodes);
        int sum = root->val + left.sum + right.sum, nodes = 1 + left.nodes + right.nodes;
      
        if (root->val == sum / nodes) goodNodes++;
        return nodesAndSum(nodes, sum);
    };
    
    int averageOfSubtree(TreeNode* root) {
        int goodNodes = 0;
        countNodes(root, goodNodes);
        return goodNodes;
    };
};