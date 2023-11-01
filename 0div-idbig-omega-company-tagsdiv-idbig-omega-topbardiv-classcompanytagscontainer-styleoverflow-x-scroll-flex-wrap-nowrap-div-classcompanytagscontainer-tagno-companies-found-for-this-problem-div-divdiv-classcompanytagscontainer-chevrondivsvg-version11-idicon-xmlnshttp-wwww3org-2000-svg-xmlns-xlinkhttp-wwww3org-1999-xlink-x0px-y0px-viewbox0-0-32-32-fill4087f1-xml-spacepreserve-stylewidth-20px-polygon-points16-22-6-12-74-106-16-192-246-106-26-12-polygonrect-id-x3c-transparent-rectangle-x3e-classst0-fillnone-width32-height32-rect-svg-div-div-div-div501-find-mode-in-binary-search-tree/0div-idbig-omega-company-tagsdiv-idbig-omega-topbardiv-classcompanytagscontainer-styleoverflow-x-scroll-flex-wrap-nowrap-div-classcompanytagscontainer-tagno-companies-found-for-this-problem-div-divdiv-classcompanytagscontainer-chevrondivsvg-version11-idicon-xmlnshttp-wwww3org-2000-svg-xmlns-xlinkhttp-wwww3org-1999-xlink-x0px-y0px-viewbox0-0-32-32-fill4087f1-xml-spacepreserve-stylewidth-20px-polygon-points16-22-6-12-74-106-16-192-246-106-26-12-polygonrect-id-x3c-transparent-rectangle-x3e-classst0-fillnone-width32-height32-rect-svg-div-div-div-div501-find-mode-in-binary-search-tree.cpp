class Solution {
public:
    void findMaxFreq(TreeNode* root, int& maxFreq, int& currVal, int& currFreq, vector<int>& ans) {
        if (!root) return;
        findMaxFreq(root->left, maxFreq, currVal, currFreq, ans);
        
        if (root->val == currVal) currFreq++;
        else currVal = root->val, currFreq = 1;
        
        if (currFreq > maxFreq) maxFreq = currFreq, ans = vector<int>();
        if (currFreq == maxFreq) ans.push_back(root->val);

        findMaxFreq(root->right, maxFreq, currVal, currFreq, ans);
    };
    
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        int maxFreq = 0, currVal = INT_MIN, currFreq = 0;
        findMaxFreq(root, maxFreq, currVal, currFreq, ans);              
        return ans;
    };
};