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
    vector<vector<string>> printTree(TreeNode* root) {
        if (!root)
            return vector<vector<string>>();
        
        // var
        int depth = calc_depth(root);
        int width = pow(2, depth) - 1;
        vector<vector<string>> result;
        
        // init
        result = vector<vector<string>>(depth, vector<string>(width, ""));

        helper(0, 0, width, root, result);
        
        return result;
    }
    
    void helper(int level, int left, int right, TreeNode* root, vector<vector<string>>& r) {
        if (!root)
            return;
        
        r[level][(left + right) / 2] = to_string(root->val);
        
        helper(level + 1, left, (left + right) / 2, root->left, r);
        helper(level + 1, (left + right) / 2, right, root->right, r);
        
    }
    
    int calc_depth(TreeNode* root) {
        if (!root)
            return 0;
        
        int left = calc_depth(root->left);
        int right = calc_depth(root->right);
        
        return max(left, right) + 1;     
    }
};