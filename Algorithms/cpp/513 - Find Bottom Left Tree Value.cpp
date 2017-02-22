/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // init
        v = vector<vector<int>>(1, vector<int>());
        
        traversal(root, 0);
        
        return v.back()[0];
    }
    
    void traversal(TreeNode* root, int level) {
        if (!root)
            return;
            
        // init
        if (v.empty() || level > v.size() - 1)
            v.push_back(vector<int>());
        
        // add
        v[level].push_back(root->val);
        
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
    
    // var
    vector<vector<int>> v;
};